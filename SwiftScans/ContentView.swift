//
//  ContentView.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI
//import ScanSDKMobile

struct ContentView: View {
	
    var body: some View {
		NavigationView {
			VStack(spacing: 22) {
				Text("Brother Scanning with SwiftUI")
					.font(.title2)
					.fontWeight(.heavy)
				
				Spacer()
				
				Group {
					ColorTypeView()
					
					ResolutionView()
					
					PaperTypeView()

					DuplexOptionView()

					DeskewOptionView()

					SkipBlankPageView()

					BrightnessView()

					ContrastView()
				}
				
				Spacer(minLength: 24)
				
				NavigationLink {
					ScannedImageView()
				} label: {
					Text("Scan")
						.font(.title3)
						.bold()
				}

			}
			.padding()
		}
		.navigationTitle("Setup")
		.navigationBarHidden(true)
        
    }
}
