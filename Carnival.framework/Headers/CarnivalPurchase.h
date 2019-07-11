//
//  CarnivalPurchase.h
//  Carnival
//
//  Created by Ian Stewart on 1/07/19.
//  Copyright © 2019 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CarnivalPurchaseItem.h"
#import "CarnivalContentItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface CarnivalPurchase : NSObject

#pragma mark - Required fields

/**
 * An array containing each item in the user’s cart.
 */
@property (strong, nonatomic, readonly) NSArray<CarnivalPurchaseItem *> *purchaseItems;


#pragma mark - Optional fields

/**
 * Any number of custom variables to attach to the order. These are commonly used with the Audience Builder “Purchase Order Var Is” query. For example, you could specify the shipping address, estimated delivery date given, credit card type used, whether a deal was used, the promo code used, etc.Note that a vars object may also exist at the item level. See the example code, and the items definition in this table.You may use any custom order variable name(s). Note that the following variable name is reserved at the order level, for a particular purpose:
    st_cost – The client’s cost for the items in the purchase, in cents. The value should be an integer, and is recommended if you are using Retention Analytics in order to report net revenue.
 */
@property (strong, nonatomic, nullable) NSDictionary<NSString *, id> *vars;

/**
 * Required to have revenue data matched to email sends in Sailthru. Pass the identifying message_id of the email the user is coming from; this will be the value stored in the sailthru_bid cookie for your domain.Note: In some client libraries message_id should be passed as a string. The message attribution will be displayed in your Campaign Summary, Transactional Report, Purchase Log, and in Lifecycle Optimizer Metrics.
 */
@property (strong, nonatomic, nullable) NSString *messageId;

- (nullable instancetype) init NS_UNAVAILABLE;
+ (nullable instancetype) new NS_UNAVAILABLE;

/**
 * Create a purchase instance with the required fields.
 *
 * @param purchaseItems The items being purchased. Can not be nil.
 * @return CarnivalPurchase instance. Will return nil if purchase items array is nil.
 */
- (nullable instancetype)initWithPurchaseItems:(NSArray<CarnivalPurchaseItem *> *)purchaseItems;

/**
 * Create a purchase instance with the required fields.
 *
 * @param contentItems The content items being purchased. Can not be nil. Must be populated with fields required for purchase.
 * @return CarnivalPurchase instance. Will return nil if purchase items array is nil.
 */
- (nullable instancetype)initWithContentItems:(NSArray<CarnivalContentItem *> *)contentItems;

/**
 * Add a custom key value pair to the purchase.
 * @discussion Adds a custom key value pair. The value must be valid for JSON serialization.
 *
 * @param key the custom value key
 * @param value the custom value
 */
- (void)addVarWithKey:(NSString *)key value:(id)value;

@end

NS_ASSUME_NONNULL_END
