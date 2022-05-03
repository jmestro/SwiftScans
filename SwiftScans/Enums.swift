//
//  Enums.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import Foundation

// Raw values map to Brother scanner enums
enum ScannerResolution:  Int, CaseIterable, CustomStringConvertible {
	case dpi100 = 0
	case dpi150 = 1
	case dpi200 = 2
	case dpi300 = 3
	case dpi400 = 4
	case dpi600 = 5
	case dpi1200 = 6
	case dpi2400 = 7
	case dpi4800 = 8
	case dpi9600 = 9
	case dpi19200 = 10
	
	var description: String {
		switch self {
		case .dpi100:
			return "100 dpi"
		case .dpi150:
			return "150 dpi"
		case .dpi200:
			return "200 dpi"
		case .dpi300:
			return "300 dpi"
		case .dpi400:
			return "400 dpi"
		case .dpi600:
			return "600 dpi"
		case .dpi1200:
			return "1200 dpi"
		case .dpi2400:
			return "2400 dpi"
		case .dpi4800:
			return "4800 dpi"
		case .dpi9600:
			return "9600 dpi"
		case .dpi19200:
			return "19200 dpi"
		}
	}
}

enum ColorType: Int, CaseIterable, CustomStringConvertible {
	case autoColor = 0
	case blackAndWhite = 1
	case errorDiffusion = 2
	case trueGray = 3
	case color24bit = 4
	
	var description: String {
		switch self {
		case .autoColor:
			return "Auto Color"
		case .blackAndWhite:
			return "Black And White"
		case .errorDiffusion:
			return "Error Diffusion"
		case .trueGray:
			return "True Gray"
		case .color24bit:
			return "Color 24 bit"
		}
	}
}

enum PaperType: Int, CaseIterable, CustomStringConvertible {
	case autoSize = 0
	case a3 = 1
	case ledger = 2
	case jisB4 = 3
	case a4 = 4
	case jisB5 = 5
	case letter = 6
	case legal = 7
	case a5 = 8
	case jisB6 = 9
	case a6 = 10
	case executive = 11
	case photo = 12
	case indexCard = 13
	case photoL = 14
	case photo2L = 15
	case postcard = 16
	case postcard2 = 17
	case businessCard90X60 = 18
	case businessCard60X90 = 19
	case folio = 20
	case mexicanLegal = 21
	case indiaLegal = 22
	case longPaperNarrowWidth = 23
	case longPaperNomalWidth = 24
	case undefined = 25
	
	var description: String {
		switch self {
		case .autoSize:
			return "AutoSize"
		case .a3:
			return "A3"
		case .ledger:
			return "Ledger"
		case .jisB4:
			return "JIS B4"
		case .a4:
			return "A4"
		case .jisB5:
			return "JIS B5"
		case .letter:
			return "Letter"
		case .legal:
			return "Legal"
		case .a5:
			return "A5"
		case .jisB6:
			return "JIS B6"
		case .a6:
			return "A6"
		case .executive:
			return "Executive"
		case .photo:
			return "Photo"
		case .indexCard:
			return "Index Card"
		case .photoL:
			return "Photo L"
		case .photo2L:
			return "Photo 2L"
		case .postcard:
			return "Postcard"
		case .postcard2:
			return "Postcard 2"
		case .businessCard90X60:
			return "Business Card 90x60"
		case .businessCard60X90:
			return "Business Card 60x90"
		case .folio:
			return "Folio"
		case .mexicanLegal:
			return "Mexican Legal"
		case .indiaLegal:
			return "Indian Legal"
		case .longPaperNarrowWidth:
			return "Long Paper Narrow Width"
		case .longPaperNomalWidth:
			return "Long Paper Nomal Width"
		case .undefined:
			return "Undefined"
		}
	}
}

enum DuplexOption: Int, CaseIterable, CustomStringConvertible {
	case simplex = 0
	case longBinding = 1
	case shortBinding = 2
	
	var description: String {
		switch self {
		case .simplex:
			return "Simplex"
		case .longBinding:
			return "Long Binding"
		case .shortBinding:
			return "Short Binding"
		}
	}
}

enum DeskewOption: CustomStringConvertible {
	case no
	case yesWithAdf
	case yesWithCardslot
	case yesWithFlatbed
	
	var description: String {
		switch self {
		case .no:
			return "No"
		case .yesWithAdf:
			return "Yes, via ADF"
		case .yesWithCardslot:
			return "Yes, via Card Slot"
		case .yesWithFlatbed:
			return "Yes, via Flatbed"
		}
	}
}

enum SkipBlankPageOption: CaseIterable, CustomStringConvertible {
	case no
	case yes
	
	var description: String {
		self == .no ? "No" : "Yes"
	}
}
