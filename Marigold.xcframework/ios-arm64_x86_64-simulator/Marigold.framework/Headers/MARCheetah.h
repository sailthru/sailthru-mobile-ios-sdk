//
//  MARCheetah.h
//  Sailthru Mobile
//
//  Created by Claude on 25/03/26.
//  Copyright © 2026 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MARCheetah : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Create a new instance of the MARCheetah class. Returns an error if `startEngine` has not been called
 * or if the MARCheetah functionality is not available.
 */
- (instancetype _Nullable)initWithError:(NSError **)error NS_SWIFT_NAME(init());

/**
 * Log a registration event with Marigold. This is used to log users signing in and out of the app.
 * Pass the ID you wish to use for the sign-in or null for a sign-out.
 *
 * @param userId The ID of the user signing in, or null for sign-out.
 * @param completionBlock The block returned from the asynchronous call. May contain an error.
 */
- (void)logRegistrationEvent:(NSString * _Nullable)userId withResponse:(nullable void(^)(NSError *__nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END
