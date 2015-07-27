//
//  Carnival.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CarnivalMessageStream.h"
#import "CarnivalStreamViewController.h"
#import "CarnivalMacros.h"

#define CARNIVAL_VERSION @"3.5.0"

__attribute__((deprecated))
@protocol CarnivalIdentifierDataSource <NSObject>

@required

/**
 *  Override this method and return the user's unique identifier for Carnival.
 *
 *  @return The user's unique identifier for Carnival.
 *
 *  @warning This method is deprecated. Please use setUserId: instead.
 */
- (carnival_nullable NSString *)carnivalUniqueIdentifier __attribute__((deprecated));

@end

@interface Carnival : NSObject

/** @name Setting up Carnival */

/**
 *  Sets the Carnival appKey credentials for this app.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is set to on http://app.carnivalmobile.com .
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences.
 */
+ (void)startEngine:(carnival_nonnull NSString *)appKey;

/**
 *  Sets the Carnival appKey credentials for this app, and the UIRemoteNotificationType at the same time.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param types The UIRemoteNotificationType attributes you wish to register this app for as defined in UIApplication.h
 *  see appledocs for more information.
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is on http://app.carnivalmobile.com .
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences.
 */
+ (void)startEngine:(carnival_nonnull NSString *)appKey andNotificationTypes:(UIRemoteNotificationType)types;

/**
 *  Sets the Carnival appKey credentials for this app and optionally registers for push notifications with the badge, alert and sound UIRemoteNotificationType's
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param registerForPushNotifications when this parameter is YES the Carnival iOS SDK will automatically register for push notifications
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences.
 */
+ (void)startEngine:(carnival_nonnull NSString *)appKey registerForPushNotifications:(BOOL)registerForPushNotifications;

/** @name Tags */

/**
 *  Asyncronously sets the tags for Carnival for this Device.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(carnival_nonnull NSArray *)tags withResponse:(carnival_nullable void(^)(NSArray *__carnival_nullable tags, NSError *__carnival_nullable error))block;

/**
 *  Asyncronously sets the tags for Carnival for this Device, with no callback block.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(carnival_nonnull NSArray *)tags;

/**
 *  Synchronously sets the tags for Carnival for this Device.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *
 *  @param error A pointer to an error which will be non-nil if there is an error.
 *
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 *
 *  @return NSArray of newly updated tags.
 */
+ (carnival_nullable NSArray *)setTags:(carnival_nonnull NSArray *)tags error:(NSError *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously adds the tags to Carnival for this Device.  If the tags are already registered with Carnival, this method does not add the tag again.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method will only add tags that are NSString's, anything else will be ignored.
 *
 *  @warning This method behaves like getTagsInBackgroundWithResponse when tags argument is nil or not an NSArray.
 */
+ (void)addTags:(carnival_nonnull NSArray *)tags inBackgroundWithResponse:(carnival_nullable void(^)(NSArray *__carnival_nullable tags, NSError *__carnival_nullable error))block;

/**
 *  Syncronously adds the tags to Carnival for this Device.  If the tags are already registered with Carnival, this method does not add the tag again.
 *
 *  @param error A pointer to an error which will be non-nil if there is an error.
 *
 *  @warning This method will only add tags that are NSString's, anything else will be ignored.
 *
 *  @warning This method behaves like getTagsInBackgroundWithResponse when tags argument is nil or not an NSArray.
 *
 *  @return NSArray of newly updated tags.
 */
+ (carnival_nullable NSArray *)addTags:(carnival_nonnull NSArray *)tags error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously gets the tags for Carnival for this Device.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method does nothing when the response block is NULL.
 */
+ (void)getTagsInBackgroundWithResponse:(carnival_nonnull void(^)(NSArray *__carnival_nullable tags, NSError *__carnival_nullable error))block;

/**
 *  Syncronously gets the tags for Carnival for this Device.
 *
 *  @param error A pointer to an error which will be non-nil if there is an error.
 *
 *  @return NSArray of newly updated tags.
 */
+ (carnival_nullable NSArray *)getTags:(NSError  *__carnival_nullable *__carnival_nullable)error;

/** @name Key/Value Attributes */

/**
 *  Asyncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
**/
+ (void)setString:(carnival_nonnull NSString *)string forKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

/**
 *  Syncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setString:(carnival_nonnull NSString *)string forKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

/**
 *  Syncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously sets an integer value for a given key.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

/**
 *  Syncronously sets an integer value for a given key.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setDate:(carnival_nonnull NSDate *)date forKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

/**
 *  Syncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setDate:(carnival_nonnull NSDate *)date forKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError  *__carnival_nullable error))block;

/**
 *  Syncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

/**
 *  Asyncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)removeAttributeWithKey:(carnival_nonnull NSString *)key withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

/**
 *  Syncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)removeAttributeWithKey:(carnival_nonnull NSString *)key error:(NSError  *__carnival_nullable *__carnival_nullable)error;

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
+ (void)updateLocation:(carnival_nonnull CLLocation *)location;

/** @name Manual Push Notification setup */

/**
 *  Asynchronously registers the APNS token for this device with the Carnival platform.
 *
 *  @param deviceToken The APNS token for the current device. This deviceToken is normally passed back by the application:didRegisterForRemoteNotificationsWithDeviceToken: method.
 */
+ (void)setDeviceTokenInBackground:(carnival_nonnull NSData *)deviceToken;

/**
 *  Tells the Carnival SDK to handle the notification.
 *
 *  @param notificationDict The userInfo dictionary from the remote notification you want the Carnival SDK to handle. This dictionary is normally passed back to you from the application:didReceiveRemoteNotification: method.
 */
+ (void)handleNotification:(carnival_nonnull NSDictionary *)notificationDict;

/** @name Identifier */

/**
 *  Sets the Identifier dataSource which gives the Carnival SDK identifier information
 *
 *  @param dataSource An object that conforms to the CarnivalIdentifierDataSource protocol
 */
+ (void)setIdentifierDataSource:(carnival_nonnull id<CarnivalIdentifierDataSource>)dataSource __attribute__((deprecated));

/** @name Device details */

/**
 *  Returns the current device's ID as a NSString
 *
 *  @param completion A block which gets called after the current device is fetched containing the current device's ID
 */
+ (void)deviceID:(carnival_nonnull void (^)(NSString *__carnival_nullable deviceID, NSError *__carnival_nullable error))completion;

/** @name Enabling/Disabling in-app notifications */

/**
 *  Enables or disables the showing of in-app notifications
 *
 *  @param enabled A boolean value indicating whether in-app notfications are enabled
 */
+ (void)setInAppNotificationsEnabled:(BOOL)enabled;

/** @name Events */

/**
 *  Logs a custom event with the given name
 *
 *  @param name The name of the custom event to be logged
 */
+ (void)logEvent:(carnival_nonnull NSString *)name;

/** @name Users */

/**
 *  Sets a user ID for the device.
 *
 *  @param userId The ID of the user to be set.
 *
 *  @param block The block returned from the asyncronous call possibly containing an error.
 */
+ (void)setUserId:(carnival_nullable NSString *)userId withResponse:(carnival_nullable void(^)(NSError *__carnival_nullable error))block;

@end
