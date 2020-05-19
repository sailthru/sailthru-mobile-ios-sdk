//
//  AppDelegate.swift
//  SwiftExampleProject
//
//  Created by Sailthru Mobile
//  Copyright (c) 2015 Sailthru Mobile. All rights reserved.
//
//  For documentation see https://docs.mobile.sailthru.com
//

import UIKit
import SailthruMobile
@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Register with Sailthru Mobile using the startEngine method using the app key for your app which you can get from https://mobile.sailthru.com
        // Could instead use the startEngine methods to customize start up.
        SailthruMobile().startEngine("1234")
        return true
    }
}
