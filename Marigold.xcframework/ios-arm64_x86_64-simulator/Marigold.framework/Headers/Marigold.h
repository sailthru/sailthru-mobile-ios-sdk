//
//  Marigold.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <UserNotifications/UserNotifications.h>
#import "MARMessageStream.h"
#import "MARAttributes.h"
#import "MARLogger.h"
#import "MARPurchase.h"
#import "MARNotificationCategory.h"
#import "EngageBySailthru.h"

NS_ASSUME_NONNULL_BEGIN

#define MAR_VERSION @"15.2.0"
FOUNDATION_EXPORT double MARSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char MARSDKVersionString[];

typedef NS_OPTIONS(NSUInteger, MARDeviceDataType) {
    MARDeviceDataTypeMessageStream  = 1 << 1,
    MARDeviceDataTypeEvents         = 1 << 2
};

typedef NS_ENUM(NSUInteger, MARPushAuthorizationOption) {
    MARPushAuthorizationOptionNoRequest,      // This option will not request any push authorization permissions for the device. Note that a push token will still be requested. No prompt is required.
    MARPushAuthorizationOptionProvisional,    // This option will request provisional push authorization, allowing push notifications to be sent to the notification center. No prompt is required. Available iOS 12+, defaults to MARPushAuthorizationOptionNoRequest behaviour for earlier versions.
    MARPushAuthorizationOptionFull            // This option will request full push authorization for alerts, sounds and badges. Note that this will prompt the user for permission.
};

/* Constants for Auto-Analytics Tracking */
extern NSString * const MARAutoAnalyticsSourceGoogleAnalytics;
extern NSString * const MARAutoAnalyticsSourceAdobeAnalytics;
extern NSString * const MARAutoAnalyticsSourceMixpanel;
extern NSString * const MARAutoAnalyticsSourceLocalytics;
extern NSString * const MARAutoAnalyticsSourceFlurryAnalytics;
extern NSString * const MARAutoAnalyticsSourceAmplitude;
extern NSString * const MARAutoAnalyticsSourceAll;

@interface Marigold : NSObject

/** @name Setting up Sailthru Mobile */

/**
 *  Sets the Sailthru Mobile appKey credentials for this app.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 *  @param error The error that will be returned if an invalid appKey is provided.
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is set to on http://mobile.sailthru.com .
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. Calls to startEngine: (overrides included) must not be made more than once.
 *
 *  @throw This method will throw an error if an invalid appKey is provided.
 */
- (BOOL)startEngine:(NSString *)appKey error:(NSError **)error;

/**
 *  Sets the Sailthru Mobile appKey credentials for this app and optionally registers for push notifications authorization. Authorization request will be determined by the pushAuthorizationOption parameter
 *  @note The device will be registered with the Apple Push Notification service and provided with a push notification token regardless of theMARPushRegistrationOption supplied. This step does not require a user prompt.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 *  @param error The error that will be returned if an invalid appKey is provided.
 *  @param pushAuthorizationOption The authorization option the SDK should use when requesting push notification authorization
 *
 *  @warning It is important that this method is called at the earliest possible opportunity (e.g. application:didFinishLaunchingWithOptions:),
 *  calling it later in the app lifecycle can have unintended consequences. Calls to startEngine: (overrides included) must not be made more than once.
 *
 *  @throw This method will throw an error if an invalid appKey is provided.
 */
- (BOOL)startEngine:(NSString *)appKey withAuthorizationOption:(MARPushAuthorizationOption)pushAuthorizationOption error:(NSError **)error;

/**
 *  Sets the logger used by Sailthru Mobile for any internal informational or debugging logging.
 *
 *  @param logger An object implementing the MARLogger protocol.
 */
- (void)setLogger:(id<MARLogger>)logger;

/** @name Custom Attributes */

/**
 *  Asyncronously clears any of the Message Stream or Event data from the device.
 *  Use this method to clear the device attributes after user logout.
 *
 *  @param types A bitwise OR collection of MARDeviceDataType dictating which sets of data to clear.
 *  @param block The block returned from the asynchronous call. May contain an error.
 **/
- (void)clearDeviceData:(MARDeviceDataType)types withResponse:(nullable void(^)(NSError *__nullable error))block __deprecated_msg("use EngageBySailthru clearEventsWithResponse: or MARMessageStream clearMessagesWithResponse: instead");

/** @name Badges */

/**
 *  Should clear the application badge automatically when the application launches.
 *  Defaults to NO on iOS versions below 5, YES on iOS versions above 5.
 */
- (void)setShouldClearBadgeOnLaunch:(BOOL)shouldClearBadgeOnLaunch;

/** @name Location tracking */

/**
 *  Forward a location to the Sailthru Mobile iOS SDK. This method can be used when you're already tracking location in your app and you just want to forward your existing calls to the Sailthru Mobile iOS SDK.
 *
 *  @param location The location to forward
 */
- (void)updateLocation:(CLLocation *)location;

/** @name Manual Push Notification setup */

/**
 *  Asynchronously registers the APNS token for this device with the Sailthru Mobile platform.
 *
 *  @param deviceToken The APNS token for the current device. This deviceToken is normally passed back by the application:didRegisterForRemoteNotificationsWithDeviceToken: method.
 */
- (void)setDeviceTokenInBackground:(NSData *)deviceToken;

/**
 * Tells the SDK to handle the notification response.
 *
 * This method should be called in the userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler: method if auto integration has been disabled in order to allow the SDK to handle the notification response.
 *
 * @param notificationResponse The response object from the notification.
 */
- (void)handleNotificationResponse:(UNNotificationResponse *)notificationResponse;

/**
 * Tells the SDK to handle a notification received while the app was in the foreground.
 *
 * This method should be called in the userNotificationCenter:willPresentNotification:withCompletionHandler: method if auto integration has been disabled in order to allow the SDK to handle the notification.
 *
 * @param notification The notification object received.
 */
- (void)handlePresentNotification:(UNNotification *)notification;

/**
 * Tells the Sailthru Mobile SDK that the notification settings have been updated and that it should synchronize the new settings with the Sailthru Mobile platform. This method is only required if auto integration has been disabled. It should be called after either the requestAuthorizationWithOptions:completionHandler: or registerUserNotificationSettings: methods have been used to request push notifications authorization.
 */
- (void)syncNotificationSettings;

/** @name Device details */

/**
 *  Returns the current device's ID as a NSString.
 *
 *  @param completion A block which gets called after the current device is fetched containing the current device's ID
 */
- (void)deviceID:(void (^)(NSString *__nullable deviceID, NSError *__nullable error))completion;

/** @name Enabling/Disabling in-app notifications */

/**
 *  Enables or disables the showing of in-app notifications.
 *
 *  @param enabled A boolean value indicating whether in-app notfications are enabled.
 */
- (void)setInAppNotificationsEnabled:(BOOL)enabled;

/**
 *  Enabled location tracking based on IP Address. Tracking location tracking is enabled by default.
 *  Use this method for users who may not want to have their location tracked at all.
 *
 *  @param enabled A boolean value indicating whether or not to disable location based on IP Address.
 */
- (void)setGeoIPTrackingEnabled:(BOOL)enabled;

/**
 *  Enabled location tracking based on IP Address. Tracking location tracking is enabled by default.
 *  Use this method for users who may not want to have their location tracked at all.
 *
 *  @param enabled A boolean value indicating whether or not to disable location based on IP Address.
 *  @param block The block to handle the result of the call. May contain an error if the call failed.
 */
- (void)setGeoIPTrackingEnabled:(BOOL)enabled withResponse:(nullable void(^)(NSError *__nullable))block;

/**
 *  Set whether location tracking based on IP Address will be enabled or disabled by default when a device is created.
 *  This method must be called before startEngine.
 *
 *  @param enabled A boolean value indicating whether or not location based on IP Address should be enabled by default.
 */
- (void)setGeoIPTrackingDefault:(BOOL)enabled;

/**
 * Log a registration event with Marigold. This is used to log users signing in and out of the app.
 * Pass the ID you wish to use for the sign-in or null for a sign-out.
 *
 * @param userId The ID of the user signing in, or null for sign-out.
 */
- (void)logRegistrationEvent:(NSString * _Nullable)userId;

/**
 *  Enable crash tracking for recording sessions which end in a crash.
 *  Warning: This is for advanced uses where in some cases, crash handlers from Test Flight or Fabric (Crashlytics) interrupt Sailthru Mobile crash detection.
 *  If you are not experiencing these issues, do not use this method.
 *
 *  @param enabled A boolean value indicating whether or not to install the crash handlers. Defaults to YES.
 */
- (void)setCrashHandlersEnabled:(BOOL)enabled;

/**
 *  Enable automatic integration for Sailthru Mobile. This must be called BEFORE startEngine, or its overloads.
 *  Warning: This is for advanced uses where you may not want Sailthru Mobile to swizzle the following UIApplicationDelegate methods:
 *  application:didRegisterForRemoteNotificationsWithDeviceToken:, application:didReceiveRemoteNotification:, application:didReceiveRemoteNotification:fetchCompletionHandler:
 *  @param enabled A boolean value indicating whether or not to swizzle notification related methods. Defaults to YES.
 */
- (void)setAutoIntegrationEnabled:(BOOL)enabled;

/**
 * Registers group names that will be used with any Extensions. This allows the MarigoldExtensionFramework to share data with the main MarigoldFramework in order to allow
 * events to be recorded in Extensions.
 *
 * @param groupNames Array of strings representing the app group names.
 */
- (void)registerExtensionGroups:(NSArray<NSString *> * _Nonnull)groupNames;

#ifdef DEBUG
/**
 * Marks this device as a development device on the platform. This will instruct the platform to send push notifications to the development APNS server for this device.
 * @warning This method should not be called in builds that will point to the APNS production environment, use only in debug or test builds.
 * @param block The block to handle the result of the call. May contain an error if the call failed.
 */
- (void)setDevelopmentDeviceWithResponse:(nullable void(^)(NSError * _Nullable))block;
#endif

@end

NS_ASSUME_NONNULL_END
