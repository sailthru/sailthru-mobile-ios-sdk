//
//  STMNotificationServiceExtension.h
//  Sailthru Mobile Extension
//
//  Created by Ian Stewart on 18/12/19.
//  Copyright © 2020 Sailthru. All rights reserved.
//

#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0))
@interface STMNotificationServiceExtension : UNNotificationServiceExtension

/**
 * Initialise a STMNotificationServiceExtension instance.
 * @param appKey The appKey you recieved when setting up your app at http://mobile.sailthru.com .
 * @param groupName The name of the app group that is shared between this extension and the main app.
 * @discussion This method should be used to create a STMNotificationServiceExtension instance. The appKey should be the same as the key used in the startEngine: call in the main SDK. The groupName must be an app group that has been applied in both the extension and the main app.
 * @return STMNotificationServiceExtension instance
 */
- (instancetype)initWithAppKey:(NSString *)appKey andGroupName:(NSString *)groupName;

@end

NS_ASSUME_NONNULL_END
