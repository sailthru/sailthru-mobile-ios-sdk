//
//  STMPurchase.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STMPurchaseItem.h"
#import "STMPurchaseAdjustment.h"

NS_ASSUME_NONNULL_BEGIN

@interface STMPurchase : NSObject

#pragma mark - Required fields

/**
 * An array containing each item in the user’s cart.
 */
@property (strong, nonatomic, readonly) NSArray<STMPurchaseItem *> *purchaseItems;


#pragma mark - Optional fields

/**
 * An array of the adjustments (positive or negative) that should be applied to the total order value. Title and price (in cents) are required.
 */
@property (strong, nonatomic, readonly) NSMutableArray<STMPurchaseAdjustment *> *purchaseAdjustments;

/**
 * Any number of custom variables to attach to the order. These are commonly used with the Audience Builder “Purchase Order Var Is” query. For example, you could specify the shipping address, estimated delivery date given, credit card type used, whether a deal was used, the promo code used, etc.Note that a vars object may also exist at the item level. See the example code, and the items definition in this table.You may use any custom order variable name(s). Note that the following variable name is reserved at the order level, for a particular purpose:
    st_cost – The client’s cost for the items in the purchase, in cents. The value should be an integer, and is recommended if you are using Retention Analytics in order to report net revenue.
 */
@property (strong, nonatomic, nullable) NSDictionary<NSString *, id> *vars;

/**
 * Required to have revenue data matched to email sends in Sailthru. Pass the identifying message_id of the email the user is coming from; this will be the value stored in the sailthru_bid cookie for your domain.Note: In some client libraries message_id should be passed as a string. The message attribution will be displayed in your Campaign Summary, Transactional Report, Purchase Log, and in Lifecycle Optimizer Metrics.
 */
@property (strong, nonatomic, nullable) NSString *messageId;

- (instancetype) init NS_UNAVAILABLE;
+ (instancetype) new NS_UNAVAILABLE;

/**
 * Create a purchase instance with the required fields.
 *
 * @param purchaseItems The items being purchased. Can not be nil.
 * @return STMPurchase instance. Will return nil if purchase items array is nil.
 */
- (nullable instancetype)initWithPurchaseItems:(NSArray<STMPurchaseItem *> *)purchaseItems;

/**
 * Create a purchase instance with the required fields.
 *
 * @param contentItems The content items being purchased. Can not be nil. Must be populated with fields required for purchase.
 * @return STMPurchase instance. Will return nil if purchase items array is nil.
 */
- (nullable instancetype)initWithContentItems:(NSArray<STMContentItem *> *)contentItems;

/**
 * Add a custom key value pair to the purchase.
 * @discussion Adds a custom key value pair. The value must be valid for JSON serialization.
 *
 * @param key the custom value key
 * @param value the custom value
 */
- (void)addVarWithKey:(NSString *)key value:(id)value;

/**
 * Add a purchase adjustment to the purchase.
 *
 * @param purchaseAdjustment The purchase adjustment (eg. discounts, shipping costs) being added to the purchase.
 */
- (void)addPurchaseAdjustment:(STMPurchaseAdjustment *)purchaseAdjustment;

/**
 * Set purchase adjustments for the purchase.
 * @note This will override any previously added purchase adjustments with the new array.
 *
 * @param purchaseAdjustments The purchase adjustments (eg. discounts, shipping costs) being applied to the purchase.
 */
- (void)setAllPurchaseAdjustments:(NSArray<STMPurchaseAdjustment *>*)purchaseAdjustments;

@end

NS_ASSUME_NONNULL_END
