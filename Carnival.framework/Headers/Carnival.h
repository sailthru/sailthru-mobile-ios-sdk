//
//  Carnival.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2017 Carnival.io. All rights reserved.
//
//  For documentation see http://docs.mobile.sailthru.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <UserNotifications/UserNotifications.h>
#import "CarnivalMessageStream.h"
#import "CarnivalAttributes.h"
#import "CarnivalLogger.h"
#import "CarnivalContentItem.h"
#import "CarnivalPurchase.h"
#import "CarnivalNotificationCategory.h"

#define CARNIVAL_VERSION @"10.1.0"
FOUNDATION_EXPORT double CarnivalSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char CarnivalSDKVersionString[];

typedef NS_OPTIONS(NSUInteger, CarnivalDeviceDataType) {
    CarnivalDeviceDataTypeAttributes     = 1 << 0,
    CarnivalDeviceDataTypeMessageStream  = 1 << 1,
    CarnivalDeviceDataTypeEvents         = 1 << 2
};

typedef NS_ENUM(NSUInteger, CarnivalPushAuthorizationOption) {
    CarnivalPushAuthorizationOptionNoRequest,      // This option will not request any push authorization permissions for the device. Note that a push token will still be requested. No prompt is required.
    CarnivalPushAuthorizationOptionProvisional,    // This option will request provisional push authorization, allowing push notifications to be sent to the notification center. No prompt is required. Available iOS 12+, defaults to CarnivalPushAuthorizationOptionNoRequest behaviour for earlier versions.
    CarnivalPushAuthorizationOptionFull            // This option will request full push authorization for alerts, sounds and badges. Note that this will prompt the user for permission.
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

__attribute__ ((deprecated("use SailthruMobile class in SailthruMobile framework instead")))
@interface Carnival : NSObject

/** @name Setting up Carnival */

/**
 *  Sets the Carnival appKey credentials for this app.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is set to on http://mobile.sailthru.com .
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. Calls to startEngine: (overrides included) must not be made more than once.
 */
+ (void)startEngine:(nonnull NSString *)appKey;

/**
 *  Sets the Carnival appKey credentials for this app and optionally registers for push notifications authorization. Authorization request will be determined by the pushAuthorizationOption parameter
 *  @note The device will be registered with the Apple Push Notification service and provided with a push notification token regardless of the CarnivalPushRegistrationOption supplied. This step does not require a user prompt.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 *  @param pushAuthorizationOption The authorization option the SDK should use when requesting push notification authorization
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. Calls to startEngine: (overrides included) must not be made more than once.
 */
+ (void)startEngine:(nonnull NSString *)appKey withAuthorizationOption:(CarnivalPushAuthorizationOption)pushAuthorizationOption;

/**
 *  Sets the logger used by Carnival for any internal informational or debugging logging.

 *  @param logger An object implementing the CarnivalLogger protocol.
 */
+ (void)setLogger:(nonnull id<CarnivalLogger>)logger;

/**
 * Enables AutoAnalytics tracking for a given array of event sources. This is opt-in as of Carnival 5.0.0.
 *
 * @param enableArray - An array of const strings beginning with CarnivalAutoAnalyticsSource.
 */
+ (void)enableAutoAnalytics:(nonnull NSArray<NSString *> *)enableArray;

/** @name Custom Attributes */

/**
 *  Asyncronously sets a CarnivalAttributes object with Carnival.
 *
 *  @param attributes A nonnull CarnivalAttributes object with the desired attributes set.
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)setAttributes:(nonnull CarnivalAttributes *)attributes withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Asyncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param block The block returned from the asynchronous call. May contain an error.
 **/
+ (void)removeAttributeWithKey:(nonnull NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Asyncronously clears any of the Attribute, Message Stream, or Event data from the device.
 *  Use this method to clear the device attributes after user logout.
 *
 *  @param types A bitwise OR collection of CarnivalDeviceDataType dictating which sets of data to clear.
 *  @param block The block returned from the asynchronous call. May contain an error.
 **/
+ (void)clearDeviceData:(CarnivalDeviceDataType)types withResponse:(nullable void(^)(NSError *__nullable error))block;


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
 * Tells the SDK to handle the notification response.
 *
 * This method should be called in the userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler: method if auto integration has been disabled in order to allow the SDK to handle the notification response.
 *
 * @param notificationResponse The response object from the notification.
 */
+ (void)handleNotificationResponse:(nonnull UNNotificationResponse *)notificationResponse API_AVAILABLE(ios(10.0));

/**
 * Tells the SDK to handle a notification received while the app was in the foreground.
 *
 * This method should be called in the userNotificationCenter:willPresentNotification:withCompletionHandler: method if auto integration has been disabled in order to allow the SDK to handle the notification.
 *
 * @param notification The notification object received.
 */
+ (void)handlePresentNotification:(nonnull UNNotification *)notification API_AVAILABLE(ios(10.0));

/**
 * Tells the SDK to handle the data from a notification payload.
 *
 * This method should be called in the application:didReceiveRemoteNotification:fetchCompletionHandler: method if auto integration has been disabled in order to allow the SDK to handle the notification data. For iOS 8 & 9 this method will execute all the notification handling previously covered by the handleNotification: method. Should be used if auto integration has been disabled in order to allow the SDK to handle the notification payload.
 *
 * @param notificationDict The userInfo dictionary from the remote notification you want the Carnival SDK to handle.
 */
+ (void)handleNotificationPayload:(nonnull NSDictionary *)notificationDict;

/**
 * Tells the Carnival SDK that the notification settings have been updated and that it should synchronize the new settings with the Carnival platform. This method is only required if auto integration has been disabled. It should be called after either the requestAuthorizationWithOptions:completionHandler: or registerUserNotificationSettings: methods have been used to request push notifications authorization.
 */
+ (void)syncNotificationSettings;

/** @name Device details */

/**
 *  Returns the current device's ID as a NSString.
 *
 *  @param completion A block which gets called after the current device is fetched containing the current device's ID
 */
+ (void)deviceID:(nonnull void (^)(NSString *__nullable deviceID, NSError *__nullable error))completion;

/** @name Sailthru Link Handling */

/**
 * If you're using Sailthru email combined with universal links, your application will open with an encoded Sailthru 'link' url.
 * This method will decode the link URL and return its destination URL, as well as making sure that the clickthrough metrics for this link are correctly attributed in Sailthru.
 * This method should be called from your AppDelegate's `application:continueUserActivity:restorationHandler:` method.
 *
 * @param url the Sailthru Link to be unrolled
 * @return the destination that the Sailthru link points to, or nil if the link isn't a valid Sailthru Link.
 */
+ (NSURL * _Nullable)handleSailthruLink:(NSURL * _Nonnull)url;

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

/**
 *  Logs a custom event with the given name and associated vars.
 *
 *  @param name The name of the custom event to be logged.
 *  @param vars The associated variables for the event.
 */
+ (void)logEvent:(nonnull NSString *)name withVars:(NSDictionary<NSString *, id> *__nullable)vars;

/** @name Users */

/**
 *  Sets a user ID for the device.
 *
 *  @param userId The ID of the user to be set.
 *
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)setUserId:(nullable NSString *)userId withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Sets a user email for the device.
 *
 *  @param userEmail The email of the user to be set.
 *
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)setUserEmail:(nullable NSString *)userEmail withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Returns the output from a Site Personalisation Manager section, an array of recommendations for the given user.
 *  It is suggested you use this in conjunction with setEmail: to identify the user to Sailthru.
 *
 *  @param sectionID An SPM section ID. The section must be set up to use JSON as the output format.
 *  @param block A block which gets called with an array of CarnivalContentItem objects and a possible error. Cannot be NULL.
 */
+ (void)recommendationsWithSection:(NSString *_Nonnull)sectionID withResponse:(nullable void(^)(NSArray<CarnivalContentItem *> * _Nullable contentItems, NSError *__nullable error))block;

/**
 *  Registers that the given pageview with Sailthru SPM.
 *
 *  @param url The URL of the content we're tracking a view of. Must be a valid URL with protocol http:// or https:// -
 *          this generally should correspond to the web link of the content being tracked, and the stored URL in the Sailthru content collection
 *  @param tags Tags for this content
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)trackPageviewWithUrl:(NSURL *_Nonnull)url andTags:(NSArray<NSString *> *_Nonnull)tags andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers that the given pageview with Sailthru SPM.
 *
 *  @param url The URL of the content we're tracking a view of. Must be a valid URL with protocol http:// or https:// -
 *              this generally should correspond to the web link of the content being tracked, and the stored URL in the Sailthru content collection
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)trackPageviewWithUrl:(NSURL *_Nonnull)url andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers an impression - a reasonable expectation that a user has seen a piece of content - with Sailthru SPM.
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being viewed
 *  @param urls a List of the URLs of the items contained within this section. Useful if multiple items
 *             of content are contained within a section, otherwise just pass a single-item array.
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)trackImpressionWithSection:(NSString *_Nonnull)sectionID andUrls:(NSArray<NSURL *> *_Nonnull)urls andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers an impression - a reasonable expectation that a user has seen a piece of content - with Sailthru SPM.
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being viewed
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)trackImpressionWithSection:(NSString *_Nonnull)sectionID andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Tracks with Sailthru SPM that a section has been tapped on, transitioning the user to a detail view
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being tapped
 *  @param url the URL of the detail being transitioned to
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
+ (void)trackClickWithSection:(NSString *_Nonnull)sectionID andUrl:(NSURL *_Nonnull)url andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Sets the profile vars on the server.
 *
 *  @param vars the vars to set on the server.
 *  @param block the block returned from the asynchronous call. May contain an error.
 */
+ (void)setProfileVars:(NSDictionary<NSString *, id> * _Nonnull)vars withResponse:(nullable void(^)(NSError * _Nullable))block;

/**
 *  Retrieves the profile vars from the server.
 *
 *  @param block the block returned from the asynchronous call. May contain an error.
 */
+ (void)getProfileVarsWithResponse:(nullable void(^)(NSDictionary<NSString *, id> * _Nullable, NSError * _Nullable))block;

/**
 *  Enabled location tracking based on IP Address. Tracking location tracking is enabled by default.
 *  Use this method for users who may not want to have their location tracked at all.
 *
 *  @param enabled A boolean value indicating whether or not to disable location based on IP Address.
 */
+ (void)setGeoIPTrackingEnabled:(BOOL)enabled;

/**
 *  Enabled location tracking based on IP Address. Tracking location tracking is enabled by default.
 *  Use this method for users who may not want to have their location tracked at all.
 *
 *  @param enabled A boolean value indicating whether or not to disable location based on IP Address.
 *  @param block The block to handle the result of the call. May contain an error if the call failed.
 */
+ (void)setGeoIPTrackingEnabled:(BOOL)enabled withResponse:(nullable void(^)(NSError *__nullable))block;

/**
 *  Set whether location tracking based on IP Address will be enabled or disabled by default when a device is created.
 *  This method must be called before startEngine.
 *
 *  @param enabled A boolean value indicating whether or not location based on IP Address should be enabled by default.
 */
+ (void)setGeoIPTrackingDefault:(BOOL)enabled;

/**
 *  Enable crash tracking for recording sessions which end in a crash.
 *  Warning: This is for advanced uses where in some cases, crash handlers from Test Flight or Fabric (Crashlytics) interrupt Carnival crash detection.
 *  If you are not experiencing these issues, do not use this method.
 *
 *  @param enabled A boolean value indicating whether or not to install the crash handlers. Defaults to YES.
 */
+ (void)setCrashHandlersEnabled:(BOOL)enabled;

/**
 *  Enable automatic integration for Carnival. This must be called BEFORE startEngine, or its overloads.
 *  Warning: This is for advanced uses where you may not want Carnival to swizzle the following UIApplicationDelegate methods:
 *  application:didRegisterForRemoteNotificationsWithDeviceToken:, application:didReceiveRemoteNotification:, application:didReceiveRemoteNotification:fetchCompletionHandler:
 *  @param enabled A boolean value indicating whether or not to swizzle notification related methods. Defaults to YES.
 */
+ (void)setAutoIntegrationEnabled:(BOOL)enabled;

/**
 * Registers group names that will be used with any Extensions. This allows the CarnivalExtensionFramework to share data with the main CarnivalFramework in order to allow
 * events to be recorded in Extensions.
 *
 * @param groupNames Array of strings representing the app group names.
 */
+ (void)registerExtensionGroups:(NSArray<NSString *> * _Nonnull)groupNames;

/**
 * Logs a purchase with Sailthru platform. This can be used for mobile purchase attribution.
 *
 * @param purchase The purchase to log with the platform.
 * @param block The block to handle the result of the call. May contain an error if the call failed.
 */
+ (void)logPurchase:(nonnull CarnivalPurchase *)purchase withResponse:(nullable void(^)(NSError * _Nullable))block;

/**
 * Logs a cart abandonment with the Sailthru platform. Use this to initiate cart abandoned flows.
 *
 * @param purchase The abandoned purchase to log with the platform.
 * @param block The block to handle the result of the call. May contain an error if the call failed.
 */
+ (void)logAbandonedCart:(nonnull CarnivalPurchase *)purchase withResponse:(nullable void(^)(NSError * _Nullable))block;

@end
