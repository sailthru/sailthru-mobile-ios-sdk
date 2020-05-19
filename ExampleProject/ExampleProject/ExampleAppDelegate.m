//
//  AppDelegate.m
//  ExampleProject
//
//  Created by Sailthru Mobile
//  Copyright (c) 2015 Sailthru Mobile. All rights reserved.
//
//  For documentation see https://docs.mobile.sailthru.com
//

#import "ExampleAppDelegate.h"
#import <SailthruMobile/SailthruMobile.h>

@implementation ExampleAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Register with Sailthru Mobile using the startEngine method using the app key for your app which you can get from https://mobile.sailthru.com
    // Could instead use the startEngine methods to customize start up.
    
    //#error Insert your app key that you got from https://mobile.sailthru.com here, then remove this line

    [[SailthruMobile new] startEngine:@"1234"];
    
    return YES;
}

@end
