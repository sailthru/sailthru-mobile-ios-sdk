//
//  SailthruMobileExtension.h
//  Sailthru Mobile
//
//  Created by Ian Stewart on 18/12/19.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "CarnivalExtension.h"

NS_ASSUME_NONNULL_BEGIN

@interface SailthruMobileExtension : CarnivalExtension

/**
 * Not available - use initWithGroupName: andAppKey: instead.
 */
- (instancetype _Nullable)init NS_UNAVAILABLE;

/**
 * Initialise an instance with the supplied group name and appKey.
 *
 * @param groupName The name of the app group this CarnivalExtension is accessing.
 * @param appKey The appKey for this app.
 *
 * @return CarnivalExtension instance.
 */
- (instancetype _Nullable)initWithAppKey:(NSString *)appKey groupName:(NSString *)groupName;

@end

NS_ASSUME_NONNULL_END
