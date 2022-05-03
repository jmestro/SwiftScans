//
//  DeskewOptionView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/2/22.
//

import SwiftUI

struct DeskewOptionView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedDeskewOption = DeskewOption.no
	
    var body: some View {
		HStack {
			Text("Deskew Option")
				.font(.subheadline)
			
			Spacer()
			
			if let supportedDeskewOptions = scanManager.supportedDeskewOptions {
				Picker("Deskew Option", selection: $selectedDeskewOption) {
					ForEach(supportedDeskewOptions, id: \.self) { deskew in
						Text(deskew.description).tag(deskew)
					}
				}
				.onChange(of: selectedDeskewOption) { newValue in
					scanManager.deskewOption = selectedDeskewOption != .no
				}
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
