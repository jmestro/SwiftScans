//
//  OCRView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/3/22.
//

import SwiftUI

struct OCRView: View {
	@EnvironmentObject var scanManager: ScanManager
	var ocrText: String
	
    var body: some View {
		VStack {
			ScrollView {
				Text(ocrText)
					.font(.body)
					.padding()
			}
		} // VStack
    }
	
	
}

