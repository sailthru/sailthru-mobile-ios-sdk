//
//  Carnival.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnival.io
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "CarnivalMessageStream.h"
#import "CarnivalAttributes.h"

#define CARNIVAL_VERSION @"5.3.1"

typedef NS_OPTIONS(NSUInteger, CarnivalDeviceDataType) {
    CarnivalDeviceDataTypeAttributes     = 1 << 0,
    CarnivalDeviceDataTypeMessageStream  = 1 << 1,
    CarnivalDeviceDataTypeEvents         = 1 << 2
};

/* Constants for Auto-Analytics Tracking */
NS_ASSUME_NONNULL_BEGIN
extern NSString * const CarnivalAutoAnalyticsSourceGoogleAnalytics;
extern NSString * const CarnivalAutoAnalyticsSourceAdobeAnalytics;
extern NSString * const CarnivalAutoAnalyticsSourceMixpanel;
extern NSString * const CarnivalAutoAnalyticsSourceLocalytics;
extern NSString * const CarnivalAutoAnalyticsSourceFlurryAnalytics;
extern NSString * const CarnivalAutoAnalyticsSourceAmplitude;
extern NSString * const CarnivalAutoAnalyticsSourceAll;
NS_ASSUME_NONNULL_END

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
 *  calling it later in the app lifecycle can have unintended consequences. No startEngine: calls (overrides included) must not be called more than once.
 */
+ (void)startEngine:(nonnull NSString *)appKey;

/**
 *  Sets the Carnival appKey credentials for this app, and the UIUserNotificationType at the same time.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param types The UIUserNotificationType attributes you wish to register this app for as defined in UIApplication.h
 *  see appledocs for more information. If targeting, iOS 7 users, please use UIUserNotificationType anyway.
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is on http://app.carnivalmobile.com .
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. No startEngine: calls (overrides included) must not be called more than once.
 */
+ (void)startEngine:(nonnull NSString *)appKey andNotificationTypes:(UIUserNotificationType)types;

/**
 *  Sets the Carnival appKey credentials for this app and optionally registers for push notifications with the badge, alert and sound UIUserNotificationType's
 *
 *  @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com .
 *  @param registerForPushNotifications when this parameter is YES the Carnival iOS SDK will automatically register for push notifications
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. No startEngine: calls (overrides included) must not be called more than once.
 */
+ (void)startEngine:(nonnull NSString *)appKey registerForPushNotifications:(BOOL)registerForPushNotifications;

/**
 * Enables AutoAnalytics tracking for a given array of event sources. This is opt-in as of Carnival 5.0.0.
 * 
 * @param enableArray - An array of const strings beginning with CarnivalAutoAnalyticsSource.
 */
+ (void)enableAutoAnalytics:(nonnull NSArray *)enableArray;

/** @name Tags
 *  @warning Tags are now deprecated in favour for setting an array of strings with setStrings:forKey: methods.
 */

/**
 *  Asyncronously sets the tags for Carnival for this Device.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(nonnull NSArray *)tags withResponse:(nullable void(^)(NSArray *__nullable tags, NSError *__nullable error))block __attribute__((deprecated("Use setStrings:forKey: instead.")));

/**
 *  Asyncronously sets the tags for Carnival for this Device, with no callback block.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 */
+ (void)setTagsInBackground:(nonnull NSArray *)tags __attribute__((deprecated("Use setStrings:forKey: instead.")));

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
+ (nullable NSArray *)setTags:(nonnull NSArray *)tags error:(NSError *__nullable *__nullable)error __attribute__((deprecated("Use setStrings:forKey: instead.")));

/**
 *  Asyncronously adds the tags to Carnival for this Device.  If the tags are already registered with Carnival, this method does not add the tag again.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method will only add tags that are NSString's, anything else will be ignored.
 *
 *  @warning This method behaves like getTagsInBackgroundWithResponse when tags argument is nil or not an NSArray.
 */
+ (void)addTags:(nonnull NSArray *)tags inBackgroundWithResponse:(nullable void(^)(NSArray *__nullable tags, NSError *__nullable error))block __attribute__((deprecated("Use setStrings:forKey: instead.")));

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
+ (nullable NSArray *)addTags:(nonnull NSArray *)tags error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("Use setStrings:forKey: instead.")));

/**
 *  Asyncronously gets the tags for Carnival for this Device.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  @warning This method does nothing when the response block is NULL.
 */
+ (void)getTagsInBackgroundWithResponse:(nonnull void(^)(NSArray *__nullable tags, NSError *__nullable error))block __attribute__((deprecated));

/**
 *  Syncronously gets the tags for Carnival for this Device.
 *
 *  @param error A pointer to an error which will be non-nil if there is an error.
 *
 *  @return NSArray of newly updated tags.
 */
+ (nullable NSArray *)getTags:(NSError  *__nullable *__nullable)error __attribute__((deprecated));

/** @name Custom Attributes */

/**
 *  Asyncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setString:(nonnull NSString *)string forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));

/**
 *  Syncronously sets a string value for a given key.
 *
 *  @param string The string value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setString:(nonnull NSString *)string forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets an array of string for a given key.
 *
 *  @param array The array of strings to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setStrings:(nonnull NSArray<NSString *> *)array forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets an array of string for a given key.
 *
 *  @param array The array of strings to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setStrings:(nonnull NSArray<NSString *> *)array forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets a float value for a given key.
 *
 *  @param aFloat The float value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setFloat:(CGFloat)aFloat forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));

/**
 *  Asyncronously sets an array of NSNumbers (which are backed by floats) for a given key.
 *
 *  @param array The array of NSNumbers, backed by floats, to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setFloats:(nonnull NSArray<NSNumber *> *)array forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets an array of NSNumbers (which are backed by floats) for a given key.
 *
 *  @param array The array of NSNumbers, backed by floats, to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setFloats:(nonnull NSArray<NSNumber *> *)array forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets an integer value for a given key. Only 32-bit Integers are supported.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets an integer value for a given key. Only 32-bit Integers are supported.
 *
 *  @param integer The integer value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setInteger:(NSInteger)integer forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets an array of NSNumbers (which are backed by integers) for a given key. Only 32-bit Integers are supported.
 *
 *  @param array The array of NSNumbers, backed by integers, to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setIntegers:(nonnull NSArray<NSNumber *> *)array forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets an array of NSNumbers (which are backed by integers) for a given key. Only 32-bit Integers are supported.
 *
 *  @param array The array of NSNumbers, backed by integers, to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setIntegers:(nonnull NSArray<NSNumber *> *)array forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setDate:(nonnull NSDate *)date forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets a date value for a given key.
 *
 *  @param date The date to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setDate:(nonnull NSDate *)date forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets an array of date values for a given key.
 *
 *  @param array The array of dates to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setDates:(nonnull NSArray<NSDate *> *)array forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets an array of date values for a given key.
 *
 *  @param array The array of dates to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setDates:(nonnull NSArray<NSDate *> *)array forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Asyncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError  *__nullable error))block __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));


/**
 *  Syncronously sets a boolean value for a given key.
 *
 *  @param boolean The boolean value to be set.
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)setBool:(BOOL)boolean forKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error __attribute__((deprecated("use setAttributes: with a CarnivalAttributes instance instead.")));

/**
 *  Asyncronously clears any of the Attribute, Message Stream, or Event data from the device.
 *  Use this method to clear the device attributes after user logout.
 *
 *  @param types A bitwise OR collection of CarnivalDeviceDataType dictating which sets of data to clear.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)clearDeviceData:(CarnivalDeviceDataType)types withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Asyncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 **/
+ (void)removeAttributeWithKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block;


/**
 *  Syncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 **/
+ (void)removeAttributeWithKey:(nonnull NSString *)key error:(NSError  *__nullable *__nullable)error;

/**
 *  Asyncronously sets a CarnivalAttributes object with Carnival.
 *
 *  @param attributes A nonnull CarnivalAttributes object with the desired attributes set.
 *  @param block The block returned from the asyncronous call possibly containing an error.
 */
+ (void)setAttributes:(nonnull CarnivalAttributes *)attributes withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Syncronously sets a CarnivalAttributes object with Carnival.
 *
 *  @param attributes A nonnull CarnivalAttributes object with the desired attributes set.
 *  @param error A pointer to an error which will be non-nil if there is an error.
 */
+ (void)setAttributes:(nonnull CarnivalAttributes *)attributes error:(NSError  *__nullable *__nullable)error;

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
+ (void)updateLocation:(nonnull CLLocation *)location;

/** @name Manual Push Notification setup */

/**
 *  Asynchronously registers the APNS token for this device with the Carnival platform.
 *
 *  @param deviceToken The APNS token for the current device. This deviceToken is normally passed back by the application:didRegisterForRemoteNotificationsWithDeviceToken: method.
 */
+ (void)setDeviceTokenInBackground:(nonnull NSData *)deviceToken;

/**
 *  Tells the Carnival SDK to handle the notification.
 *
 *  @param notificationDict The userInfo dictionary from the remote notification you want the Carnival SDK to handle. This dictionary is normally passed back to you from the application:didReceiveRemoteNotification: method.
 */
+ (void)handleNotification:(nonnull NSDictionary *)notificationDict;

/** @name Device details */

/**
 *  Returns the current device's ID as a NSString.
 *
 *  @param completion A block which gets called after the current device is fetched containing the current device's ID
 */
+ (void)deviceID:(nonnull void (^)(NSString *__nullable deviceID, NSError *__nullable error))completion;

/** @name Enabling/Disabling in-app notifications */

/**
 *  Enables or disables the showing of in-app notifications.
 *
 *  @param enabled A boolean value indicating whether in-app notfications are enabled.
 */
+ (void)setInAppNotificationsEnabled:(BOOL)enabled;

/** @name Events */

/**
 *  Logs a custom event with the given name.
 *
 *  @param name The name of the custom event to be logged.
 */
+ (void)logEvent:(nonnull NSString *)name;

/** @name Users */

/**
 *  Sets a user ID for the device.
 *
 *  @param userId The ID of the user to be set.
 *
 *  @param block The block returned from the asyncronous call possibly containing an error.
 */
+ (void)setUserId:(nullable NSString *)userId withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Sets a user email for the device.
 *
 *  @param userEmail The email of the user to be set.
 *
 *  @param block The block returned from the asyncronous call possibly containing an error.
 */
+ (void)setUserEmail:(nullable NSString *)userEmail withResponse:(nullable void(^)(NSError *__nullable error))block;


/**
 *  Enabled location tracking based on IP Address. Tracking location tracking is enabled by default.
 *  Use this method for users who may not want to have their location tracked at all.
 *
 *  @param disabled A boolean value indicating whether or not to disable location based on IP Address.
 */
+ (void)setGeoIPTrackingEnabled:(BOOL)enabled;

/**
 *  Enable crash tracking for recording sessions which end in a crash.
 *  Warning: This is for advanced uses where in some cases, crash handlers from Test Flight or Fabric (Crashlytics) interrupt Carnival crash detection.
 *  If you are not experiencing these issues, do not use this method. 
 *
 *  @param disabled A boolean value indicating whether or not to install the crash handlers. Defaults to YES.
 */
+ (void)setCrashHandlersEnabled:(BOOL)enabled;

/**
 *  Enable automatic integration for Carnival. This must be called BEFORE startEngine, or its overloads.
 *  Warning: This is for advanced uses where you may not want Carnival to swizzle the following UIApplicationDelegate methods:
 *  application:didRegisterForRemoteNotificationsWithDeviceToken:, application:didReceiveRemoteNotification:, application:didReceiveRemoteNotification:fetchCompletionHandler:
 *  @param disabled A boolean value indicating whether or not to swizzle notification related methods. Defaults to YES.
 */
+ (void)setAutoIntegrationEnabled:(BOOL)enabled;

@end
