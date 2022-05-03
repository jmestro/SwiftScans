//
//  PaperType.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI

struct PaperTypeView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedPaperType = PaperType.autoSize
	
    var body: some View {
		HStack {
			Text("Paper Type")
				.font(.subheadline)
			
			Spacer()
			
			if let supportedPaperTypes = scanManager.supportedPaperTypes {
				Picker("Paper Type", selection: $selectedPaperType) {
					ForEach(supportedPaperTypes, id: \.self) { paper in
						Text(paper.description).tag(paper)
					}
				}
				.onAppear {
					selectedPaperType = scanManager.paperType
				}
				.onChange(of: selectedPaperType) { newValue in
					scanManager.paperType = newValue
				}
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
