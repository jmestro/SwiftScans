//
//  ScanManager.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import Foundation
import ScanSDKMobile
import SwiftUI

class ScanManager: ObservableObject {
	@Published var scannedImage: UIImage?
	
	// Track user scanning options and provide applicable supported
	// scanner options and settings.
	var colorType: ColorType = .blackAndWhite
	var supportedColorTypes: [ColorType]?
	
	var resolution: ScannerResolution = .dpi100
	var supportedResolutions: [ScannerResolution]?
	
	var paperType: PaperType = .letter
	var supportedPaperTypes: [PaperType]?
	
	var duplexOption: DuplexOption = .simplex
	var supportedDuplexOptions: [DuplexOption]?
	
	var deskewOption: Bool?
	var supportedDeskewOptions: [DeskewOption]?
	
	var skipBlankPageOption: Bool?
	var supportedSkipBlankPageOptions: [SkipBlankPageOption]?
	
	var brightness = 0.0
	
	var contrast = 0.0
	
	// Keep the Brother SDK hidden
	private var scannerSDK: ScanSDKObjc!
	private var workingDirectory: URL!
	private var capabilities = SCCapability()
	private var parameters = SCScanParameter()
	
	init(scannerIP: String) {
		workingDirectory = FileManager.default.urls(for: .cachesDirectory, in: .userDomainMask).first!
		scannerSDK = ScanSDKObjc(workingDirectory.path)
		
		var error = scannerSDK.selectDevice(scannerIP)
		guard error == .noErrors else {
			fatalError("Printer not found on network")
		}
		
		error = scannerSDK.queryCapabilities(capabilities)
		guard error == .noErrors else  {
			fatalError("Query capability error: \(error.rawValue)")
		}
		
		error = scannerSDK.getScanParameter(&parameters)
		guard error == .noErrors else  {
			fatalError("Failed to get default scan parameter.")
		}
		
		// Retrieve scanner capabilities and options
		// Available color type processing is indicated with bools. For consistency an
		// array of ColorType is returned.
		if capabilities.colorType.autoColor.boolValue {
			(supportedColorTypes?.append(.autoColor)) ?? (supportedColorTypes = [.autoColor])
		}
		if capabilities.colorType.blackAndWhite.boolValue {
			(supportedColorTypes?.append(.blackAndWhite)) ?? (supportedColorTypes = [.blackAndWhite])
		}
		if capabilities.colorType.errorDiffusion.boolValue {
			(supportedColorTypes?.append(.errorDiffusion)) ?? (supportedColorTypes = [.errorDiffusion])
		}
		if capabilities.colorType.trueGray.boolValue {
			(supportedColorTypes?.append(.trueGray)) ?? (supportedColorTypes = [.trueGray])
		}
		if capabilities.colorType.color24bit.boolValue {
			(supportedColorTypes?.append(.color24bit)) ?? (supportedColorTypes = [.color24bit])
		}
		if supportedColorTypes != nil {
			colorType = ColorType(rawValue: parameters.colorType.rawValue)!
		}
		
		// Available resolutions are returned as an array of Any which is cast to Int.
		// The DS-940DW returns an extra resolution of 1200 dpi, which is interpolated
		// from the standard 600 dpi.
		if let resolutions = capabilities.resolutionList as? [Int] {
			supportedResolutions = resolutions.map{ ScannerResolution(rawValue: $0)! }
		}
		if supportedResolutions != nil {
			resolution = ScannerResolution(rawValue: parameters.resolution.rawValue)!
		}
		
		// An undefined paper type with a raw value of 25 is returned. You should
		// remove this as an available option in your own app.
		if let paperTypes = capabilities.paperTypeList as? [Int] {
			supportedPaperTypes = paperTypes.map{ PaperType(rawValue: $0)! }
		}
		if supportedPaperTypes != nil {
			paperType = PaperType(rawValue: parameters.scanArea.paperType.rawValue)!
		}
		
		// Duplex capability is returned as a bool. If available, you have three
		// type of duplexing (simplex is no duplexing).
		if capabilities.duplex {
			supportedDuplexOptions = DuplexOption.allCases
			duplexOption = DuplexOption(rawValue: parameters.duplex.rawValue) ?? .simplex
		}
		
		// Deskew capability may be limited to the paper source on the scanner.
		// The source properties are: adf, cardslot and flatbed. Check the availability by
		// examining the boolean property via:
		// capabilities.autoDeskew.papersource.<property name>.boolValue
		if capabilities.autoDeskew.support.boolValue {
			supportedDeskewOptions = [.no]
			if capabilities.autoDeskew.paperSource.adf.boolValue {
				supportedDeskewOptions?.append(.yesWithAdf)
			}
			if capabilities.autoDeskew.paperSource.cardslot.boolValue {
				supportedDeskewOptions?.append(.yesWithCardslot)
			}
			if capabilities.autoDeskew.paperSource.flatbed.boolValue {
				supportedDeskewOptions?.append(.yesWithFlatbed)
			}
		}
		if parameters.autoDeskew.boolValue {
			deskewOption = true
		}
		
		if capabilities.skipBlankPage {
			supportedSkipBlankPageOptions = SkipBlankPageOption.allCases
		}
		if parameters.skipBlankPage.execute.boolValue {
			skipBlankPageOption = true
		}
		
		brightness = Double(parameters.brightness)
		
		contrast = Double(parameters.contrast)
	} // init
	
	func setScannerParameters() {
		parameters.colorType = SCColorType(rawValue: colorType.rawValue)!
		parameters.resolution = SCResolution(rawValue: resolution.rawValue)!
		parameters.scanArea.paperType = SCPaperType(rawValue: paperType.rawValue)!
		parameters.duplex = SCDuplexType(rawValue: duplexOption.rawValue)!
		if let deskewOption = deskewOption {
			parameters.autoDeskew = ObjCBool(deskewOption)
		} else {
			parameters.autoDeskew = ObjCBool(false)
		}
		if let skipBlankPageOption = skipBlankPageOption {
			parameters.skipBlankPage.execute = ObjCBool(skipBlankPageOption)
		} else {
			parameters.skipBlankPage.execute = ObjCBool(false)
		}
		parameters.brightness = Int32(brightness)
		parameters.contrast = Int32(contrast)
		
		let error = scannerSDK.setScanParameter(parameters)
		guard error == .noErrors else {
			fatalError("Failed to set user selected parameters")
		}
	}
	
	func scan() {
		let error = scannerSDK.scanAsync()
		guard error == .noErrors else {
			fatalError("Scanning has failed: \(error.rawValue)")
		}
		
		var currentPage = 1
		
		while scannerSDK.getScanStatus() == .scanning || scannerSDK.hasScanData(currentPage) {
			if !scannerSDK.hasScanData(currentPage) {
				Thread.sleep(forTimeInterval: 0.01)
				continue
			}
			
			let scanDataInfo = SCScanDataInfo()
			if let scannedImagePath = scannerSDK.getScanData(currentPage, into: workingDirectory.path, fileNamePrefix: "sample_", scanDataInfo: scanDataInfo) {
				let scannedImageURL = URL(fileURLWithPath: scannedImagePath)
				scannedImage = UIImage(contentsOfFile: scannedImageURL.path)
			} else {
				fatalError("Failed to get scanned image at: \(workingDirectory.path)")
			}
			
			currentPage += 1
		} // while
		
		let state = scannerSDK.getScanStatus()
		if state == .allEnd || state == .standby {
			print("Scan completed")
		} else if state == .canceled {
			print("Scan canceled")
		} else {
			print("Failed to scan")
		}
	}
	
}
