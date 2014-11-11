//
//  AppDelegate.m
//  ExampleProject
//
//  Created by Blair McArthur on 19/12/13.
//  Copyright (c) 2013 Carnival Labs. All rights reserved.
//

#import "ExampleAppDelegate.h"
#import <Carnival/Carnival.h>

@implementation ExampleAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Register with Carnival using the startEngine method using the app key for your app which you can get from http://app.carnivalmobile.com
    // Could instead use the startEngine:andNotificationTypes: method to register for specific UIRemoteNotificationType's
    
    #error Insert your app key that you got from http://app.carnivalmobile.com here, then remove this line
    
    [Carnival startEngine:<#app key#>];
    
    return YES;
}

@end
