//
//  AppDelegate.swift
//  SwiftExampleProject
//
//  Created by Blair McArthur on 10/09/14.
//  Copyright (c) 2014 Carnival Labs. All rights reserved.
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