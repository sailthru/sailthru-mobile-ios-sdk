//
//  AppDelegate.swift
//  SwiftExampleProject
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?

    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Register with Carnival using the startEngine method using the app key for your app which you can get from http://app.carnivalmobile.com
        // Could instead use the startEngine:andNotificationTypes: method to register for specific UIRemoteNotificationType's
        Carnival.startEngine(<#app key#>)
        
        return true
    }
}