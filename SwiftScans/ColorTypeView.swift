//
//  ColorType.swift
//  BroScanSwift
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI

struct ColorTypeView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedColor = ColorType.blackAndWhite
	
    var body: some View {
		HStack {
			Text("Color Type")
				.font(.subheadline)
			
			Spacer()

			if let supportedColorTypes = scanManager.supportedColorTypes {
				Picker("Color Type", selection: $selectedColor) {
					ForEach(supportedColorTypes, id: \.self) { color in
						Text(color.description).tag(color)
					}
				}
				.onAppear {
					selectedColor = scanManager.colorType
				}
				.onChange(of: selectedColor, perform: { newValue in
					scanManager.colorType = newValue
				})
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
