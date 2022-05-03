//
//  Resolution.swift
//  BroScanSwift
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI

struct ResolutionView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedResolution = ScannerResolution.dpi100
	
    var body: some View {
		HStack {
			Text("Resolution")
				.font(.subheadline)
			
			Spacer()
			
			if let supportedResolutions = scanManager.supportedResolutions {
				Picker("Resolution", selection: $selectedResolution) {
					ForEach(supportedResolutions, id: \.self) { res in
						Text(res.description).tag(res)
					}
				}
				.onAppear {
					selectedResolution = scanManager.resolution
				}
				.onChange(of: selectedResolution) { newValue in
					scanManager.resolution = newValue
				}
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
