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

#define CARNIVAL_VERSION @"3.4.0"

@protocol CarnivalIdentifierDataSource <NSObject>

@required

/**
 *  Override this method and return the user's unique identifier for Carnival.
 *
 *  @return The user's unique identifier for Carnival.
 */
- (NSString *)carnivalUniqueIdentifier;

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
+ (void)startEngine:(NSString *)appKey;

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
+ (void)startEngine:(NSString *)appKey andNotificationTypes:(UIRemoteNotificationType)types;

/**
 *  Sets the Carnival appKey credentials for this app and optionally registers for push notifications with the badge, alert and sound UIRemoteNotificationType's
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param registerForPushNotifications when this parameter is YES the Carnival iOS SDK will automatically register for push notifications
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences.
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
+ (NSArray *)setTags:(NSArray *)tags error:(NSError **)error;

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
+ (NSArray *)addTags:(NSArray *)tags error:(NSError **)error;

/**
 *  Asyncronously gets the tags for Carnival for this Device.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method does nothing when the response block is NULL.
 */
+ (void)getTagsInBackgroundWithResponse:(void(^)(NSArray *tags, NSError *error))block;

/**
 *  Syncronously gets the tags for Carnival for this Device.
 *
 *  @param error A pointer to an error which will be non-nil if there is an error.
 *
 *  @return NSArray of newly updated tags.
 */
+ (NSArray *)getTags:(NSError **)error;

/** @name Key/Value Attributes */

/**
 *  Asyncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
**/
+ (void)setString:(NSString *)string forKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setString:(NSString *)string forKey:(NSString *)key error:(NSError * __autoreleasing *)error;

/**
 *  Asyncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(NSString *)key error:(NSError * __autoreleasing *)error;

/**
 *  Asyncronously sets an integer value for a given key.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously sets an integer value for a given key.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(NSString *)key error:(NSError * __autoreleasing *)error;

/**
 *  Asyncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setDate:(NSDate *)date forKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setDate:(NSDate *)date forKey:(NSString *)key error:(NSError * __autoreleasing *)error;

/**
 *  Asyncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(NSString *)key error:(NSError * __autoreleasing *)error;

/**
 *  Asyncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)removeAttributeWithKey:(NSString *)key withResponse:(void(^)(NSError *error))block;

/**
 *  Syncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)removeAttributeWithKey:(NSString *)key error:(NSError * __autoreleasing *)error;;

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

/** @name Identifier */

/**
 *  Sets the Identifier dataSource which gives the Carnival SDK identifier information
 *
 *  @param dataSource An object that conforms to the CarnivalIdentifierDataSource protocol
 */
+ (void)setIdentifierDataSource:(id<CarnivalIdentifierDataSource>)dataSource;

/** @name Device details */

/**
 *  Returns the current device's ID as a NSString
 *
 *  @param completion A block which gets called after the current device is fetched containing the current device's ID
 */
+ (void)deviceID:(void (^)(NSString *deviceID, NSError *error))completion;

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
+ (void)logEvent:(NSString *)name;

@end
