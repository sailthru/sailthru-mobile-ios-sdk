//
//  SailthruMobileExtension.h
//  Sailthru Mobile Extension
//
//  Created by Ian Stewart on 18/12/19.
//  Copyright © 2020 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

@interface SailthruMobileExtension : NSObject

/**
 * Not available - use initWithGroupName: andAppKey: instead.
 */
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * Initialise an instance with the supplied group name and appKey.
 *
 * @param groupName The name of the app group this SailthruMobileExtension is accessing.
 * @param appKey The appKey for this app.
 *
 * @return SailthruMobileExtension instance.
 */
- (instancetype _Nullable)initWithAppKey:(NSString *)appKey groupName:(NSString *)groupName;

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
