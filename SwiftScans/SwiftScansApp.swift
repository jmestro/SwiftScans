//
//  SwiftScansApp.swift
//  SwiftScans
//
//  Created by Joe Mestrovich on 5/1/22.
//

import SwiftUI

@main
struct SwiftScansApp: App {
	var scannerManager = ScanManager(scannerIP: "10.0.1.7")
	
    var body: some Scene {
        WindowGroup {
            ContentView()
				.environmentObject(scannerManager)
        }
    }
}
