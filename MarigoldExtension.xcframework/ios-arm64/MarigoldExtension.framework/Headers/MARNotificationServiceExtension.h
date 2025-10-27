//
//  MARNotificationServiceExtension.h
//  Sailthru Mobile Extension
//
//  Created by Ian Stewart on 18/12/19.
//  Copyright © 2020 Sailthru. All rights reserved.
//

#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

@interface MARNotificationServiceExtension : UNNotificationServiceExtension

/**
 * Initialise a MARNotificationServiceExtension instance.
 * @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 * @param groupName The name of the app group that is shared between this extension and the main app.
 * @discussion This method should be used to create a MARNotificationServiceExtension instance. The appKey should be the same as the key used in the startEngine: call in the main SDK. The groupName must be an app group that has been applied in both the extension and the main app.
 * @return MARNotificationServiceExtension instance
 */
- (instancetype)initWithAppKey:(NSString *)appKey andGroupName:(NSString *)groupName;

/**
 * Determines the appropriate file extension for a downloaded attachment based on the URL and HTTP response.
 *
 * @param url The original URL of the attachment.
 * @param response The HTTP response from downloading the attachment.
 * @return A file extension string (including the dot, e.g., ".gif", ".jpg", ".png") to use for the downloaded file.
 * @discussion This method prioritizes Content-Type headers for dynamic URLs, then falls back to URL path extensions, and finally provides sensible defaults. Supports common image formats (.gif, .jpg, .png, .webp) and video formats (.mp4, .mov). For unknown content types, defaults to .jpg.
 */
- (NSString *)fileExtensionForURL:(NSURL * _Nullable)url response:(NSURLResponse * _Nullable)response;

@end

NS_ASSUME_NONNULL_END
