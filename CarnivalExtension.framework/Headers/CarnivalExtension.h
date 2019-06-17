//
//  CarnivalExtension.h
//  Carnival
//
//  Created by Ian Stewart on 28/02/19.
//  Copyright © 2019 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

@interface CarnivalExtension : NSObject

/**
 * Sets the Carnival appKey credentials for this app extension.
 *
 * @param appKey The appKey you recieved when setting up your app at http://app.carnivalmobile.com.
 * @discussion This method should be called when as soon as possible within the extension to setup the appKey.
 */
+ (void)startEngine:(NSString *)appKey;

/**
 * Retrieve an instance of the CarnivalExtension class for the supplied group name.
 *
 * @param groupName The name of the app group this extension shares with the main app.
 * @discussion The app group needs to be setup in the Capabilites section for both the primary app and the app extension in order for events to be logged.
 *
 * @return CarnivalExtension instance
 */
+ (CarnivalExtension * _Nullable)getInstanceForGroup:(NSString *)groupName;

/**
 * Handles the notification request that caused the extension to be executed.
 *
 * @param notificationRequest The notification request that was passed to the extension.
 * @discussion This method should be called in the UNNotificationServiceExtension didReceiveNotificationRequest:withContentHandler: method. The notification request needs to be handled to ensure events are logged against the correct notification. This should be called before any logEvent calls are made.
 */
- (void)handleNotificationRequest:(UNNotificationRequest *)notificationRequest API_AVAILABLE(ios(10.0));

/**
 * Handles the notification that caused the extension to be executed.
 *
 * @param notification The notification that was passed to the extension.
 * @discussion This method should be called in the UNNotificationContentExtension didReceiveNotification: method. The notification needs to be handled to ensure events are logged against the correct notification. This should be called before any logEvent calls are made.
 */
- (void)handleNotification:(UNNotification *)notification API_AVAILABLE(ios(10.0));

/**
 * Log an extension event.
 *
 * @param eventName The name of the extension event to be logged.
 * @discussion This will log the extension event. Events are batched and sent to the in groups once the event threshold has been met. Otherwise they will be dispatched the next time the main app is launched.
 */
- (void)logEvent:(NSString *)eventName;

/**
 * Log an extension event.
 *
 * @param eventName The name of the extension event to be logged.
 * @param vars The associated variables for the event.
 * @discussion This will log the extension event. Events are batched and sent to the in groups once the event threshold has been met. Otherwise they will be dispatched the next time the main app is launched.
 */
- (void)logEvent:(NSString *)eventName withVars:(NSDictionary<NSString *, id> * _Nullable)vars;

@end

NS_ASSUME_NONNULL_END
