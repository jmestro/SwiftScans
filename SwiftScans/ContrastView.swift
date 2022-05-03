//
//  ContrastView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/2/22.
//

import SwiftUI

struct ContrastView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var contrast = 0.0
	
    var body: some View {
		HStack {
			Text("Contrast (\(contrast, specifier: "%.f"))")
				.font(.subheadline)
			
			Spacer()
			
			Slider(value: $contrast, in: -50 ... 50)
				.frame(width: 130)
				.onAppear {
					contrast = scanManager.contrast
				}
				.onChange(of: contrast) { newValue in
					scanManager.contrast = contrast
				}
			
		}
    }
}

struct ContrastView_Previews: PreviewProvider {
    static var previews: some View {
        ContrastView()
    }
}
