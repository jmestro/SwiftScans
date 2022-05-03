//
//  DuplexOptionView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI

struct DuplexOptionView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedDuplexOption = DuplexOption.simplex

    var body: some View {
		HStack {
			Text("Duplex Option")
				.font(.subheadline)
			
			Spacer()
			
			if let supportedDuplexOptions = scanManager.supportedDuplexOptions {
				Picker("Duplex Option", selection: $selectedDuplexOption) {
					ForEach(supportedDuplexOptions, id: \.self) { duplex in
						Text(duplex.description).tag(duplex)
					}
				}
				.onAppear {
					selectedDuplexOption = scanManager.duplexOption
				}
				.onChange(of: selectedDuplexOption) { newValue in
					scanManager.duplexOption = newValue
				}
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
