//
//  BrightnessView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/2/22.
//

import SwiftUI

struct BrightnessView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var brightness = 0.0
	
    var body: some View {
		HStack {
			Text("Brightness (\(brightness, specifier: "%.f"))")
				.font(.subheadline)
			
			Spacer()
			
			Slider(value: $brightness, in: -50 ... 50)
				.frame(width: 130)
				.onAppear {
					brightness = scanManager.brightness
				}
				.onChange(of: brightness) { newValue in
					scanManager.brightness = brightness
				}
		}
    }
}
