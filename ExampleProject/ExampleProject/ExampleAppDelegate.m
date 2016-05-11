//
//  AppDelegate.m
//  ExampleProject
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

#import "ExampleAppDelegate.h"
#import <Carnival/Carnival.h>

@implementation ExampleAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Register with Carnival using the startEngine method using the app key for your app which you can get from http://app.carnivalmobile.com
    // Could instead use the startEngine methods to customize start up.
    
    #error Insert your app key that you got from http://app.carnivalmobile.com here, then remove this line

    [Carnival startEngine:app key];
    
    return YES;
}

@end
