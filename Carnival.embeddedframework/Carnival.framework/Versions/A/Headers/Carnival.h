//
//  Carnival.h
//  Carnival
//
//  Created by Adam Jones on 22/02/12.
//  Copyright (c) 2012 Carnival Labs . All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//
//  Built 29 August 2012

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CarnivalMessageStream.h"

#define CARNIVAL_VERSION @"2.9"

@interface Carnival : NSObject

/** @name Setting up Carnival */

/**
 *  Sets the Carnival appKey credentials for this app.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is set to on http://app.carnivalmobile.com .
 *
 */
+ (void)startEngine:(NSString *)appKey;

/**
 *  Sets the Carnival appKey credentials for this app, and the UIRemoteNotificationType at the same time.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param types The UIRemoteNotificationType attributes you wish to register this app for as defined in UIApplication.h
 *  see appledocs for more information.
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is on http://app.carnivalmobile.com .
 */
+ (void)startEngine:(NSString *)appKey andNotificationTypes:(UIRemoteNotificationType)types;

/**
 *  Sets the Carnival appKey credentials for this app and optionally registers for push notifications with the badge, alert and sound UIRemoteNotificationType's
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param registerForPushNotifications when this parameter is YES the Carnival iOS SDK will automatically register for push notifications
 */
+ (void)startEngine:(NSString *)appKey registerForPushNotifications:(BOOL)registerForPushNotifications;

/** @name Tags */

/**
 *  Asyncronously sets the tags for Carnival for this Device.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(NSArray *)tags withResponse:(void(^)(NSArray *tags, NSError *error))block;

/**
 *  Asyncronously sets the tags for Carnival for this Device, with no callback block.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(NSArray *)tags;

/**
 *  Asyncronously adds the tag to Carnival for this Device.  If the tag is already registered with Carnival, this method does not add the tag again.
 *
 *  @deprecated use the addTags: method instead
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method behaves like getTagsInBackgroundWithResponse when the added tag is nil or not an NSString.
 */
+ (void)addTag:(NSString *)tag inBackgroundWithResponse:(void (^)(NSArray *tags, NSError *error))block __attribute((deprecated("use the addTags: method instead")));

/**
 *  Asyncronously adds the tags to Carnival for this Device.  If the tags are already registered with Carnival, this method does not add the tag again.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method will only add tags that are NSString's, anything else will be ignored.
 *
 *  @warning This method behaves like getTagsInBackgroundWithResponse when tags argument is nil or not an NSArray.
 */
+ (void)addTags:(NSArray *)tags inBackgroundWithResponse:(void(^)(NSArray *tags, NSError *error))block;

/**
 *  Asyncronously gets the tags for Carnival for this Device.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method does nothing when the response block is NULL.
 */
+ (void)getTagsInBackgroundWithResponse:(void(^)(NSArray *tags, NSError *error))block;

/** @name Badges */

/**
 *  Should clear the application badge automatically when the application launches.
 *  Defaults to NO on iOS versions below 5, YES on iOS versions above 5.
 */
+ (void)setShouldClearBadgeOnLaunch:(BOOL)shouldClearBadgeOnLaunch;

/** @name Location tracking */

/**
 *  Forward a location to the Carnival iOS SDK. This method can be used when you're already tracking location in your app and you just want to forward your existing calls to the Carnival iOS SDK.
 *
 *  @param location The location to forward
 */

+ (void)updateLocation:(CLLocation *)location;

/** @name Manual Push Notification setup */

/**
 *  Asynchronously registers the APNS token for this device with the Carnival platform.
 *
 *  @param deviceToken The APNS token for the current device. This deviceToken is normally passed back by the application:didRegisterForRemoteNotificationsWithDeviceToken: method.
 */
+ (void)setDeviceTokenInBackground:(NSData *)deviceToken;

/**
 *  Tells the Carnival SDK to handle the notification.
 *
 *  @param notificationDict The userInfo dictionary from the remote notification you want the Carnival SDK to handle. This dictionary is normally passed back to you from the application:didReceiveRemoteNotification: method.
 */
+ (void)handleNotification:(NSDictionary *)notificationDict;

@end
