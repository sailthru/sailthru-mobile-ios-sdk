//
//  STMPurchaseAdjustment.h
//  Sailthru Mobile
//
//  Created by Bea Jayme on 9/02/21.
//  Copyright © 2021 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STMContentItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface STMPurchaseAdjustment : NSObject

#pragma mark - Required fields

/**
 * Short user-readable name/title of the purchase adjustment.
 */
@property (strong, nonatomic, readonly) NSString *title;

/**
 * Price of one purchase adjustment, in cents (e.g. $10.99 is 1099).
 */
@property (strong, nonatomic, readonly) NSNumber *price;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * Create a purchase adjustment instance with the required fields.
 *
 * @param title    The title of the purchase adjustment. Must not be nil.
 * @param price    The cost of a single purchase adjustment in cents.
 * @return STMPurchaseAdjustment instance. Will return nil if nil parameters are passed.
 */
- (nullable instancetype)initWithTitle:(NSString *)title
                                 price:(NSInteger)price;

@end

NS_ASSUME_NONNULL_END
