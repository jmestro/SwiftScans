//
//  SkipBlankPageView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/2/22.
//

import SwiftUI

struct SkipBlankPageView: View {
	@EnvironmentObject var scanManager: ScanManager
	@State var selectedSkipBlankPageOption = SkipBlankPageOption.no
	
    var body: some View {
		HStack {
			Text("Skip Blank Page")
				.font(.subheadline)
			
			Spacer()
			
			if let supportedSkipBlankPageOptions = scanManager.supportedSkipBlankPageOptions {
				Picker("Skip Blank Page Option", selection: $selectedSkipBlankPageOption) {
					ForEach(supportedSkipBlankPageOptions, id: \.self) { skip in
						Text(skip.description).tag(skip)
					}
				}
				.onChange(of: selectedSkipBlankPageOption) { newValue in
					scanManager.skipBlankPageOption = selectedSkipBlankPageOption != .no
				}
			} else {
				Text("Unavailable")
					.font(.subheadline)
					.disabled(true)
			}
			
		}
    }
}
