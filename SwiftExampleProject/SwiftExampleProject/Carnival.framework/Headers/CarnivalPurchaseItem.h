//
//  CarnivalPurchaseItem.h
//  Carnival
//
//  Created by Ian Stewart on 1/07/19.
//  Copyright © 2019 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CarnivalContentItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface CarnivalPurchaseItem : NSObject

#pragma mark - Required fields

/**
 * Quantity of the item purchased.
 */
@property (strong, nonatomic, readonly) NSNumber *quantity;

/**
 * Short user-readable name/title of the item purchased.
 */
@property (strong, nonatomic, readonly) NSString *title;

/**
 * Price of one item, in cents (e.g. $10.99 is 1099).
 */
@property (strong, nonatomic, readonly) NSNumber *price;

/**
 * Your unique identifier (for example, SKU) for the item.
 */
@property (strong, nonatomic, readonly) NSString *purchaseItemID;

/**
 * The URL of the item. Note: The domain and scheme are case sensitive but paths are not. For example, if the stored URL is https://sailthru.com/Product, then Https://Sailthru.com/product would fail to match the product, but https://sailthru.com/product would.
 */
@property (strong, nonatomic, readonly) NSURL *URL;


#pragma mark - Optional fields

/**
 * A list of tags applicable to the product.
 */
@property (strong, nonatomic, nullable) NSArray<NSString *> *tags;

/**
 * Any number of custom fields and values to attach to each item for later retrieval in templates or use in Audience Builder or Lifecycle Optimizer. For example, you may want to specify item attributes such as color, size, material, or an item-specific coupon code that was used.
 * Must be a valid JSON object. Invalid objects will be discarded.
 */
@property (strong, nonatomic, nullable) NSDictionary<NSString *, id> *vars;

/**
 * A map of image types full and/or thumb to objects specifying the URL for each image. Use the name “full” to denote the full-sized image, and “thumb” to denote the thumbnail-sized image. For example, the value of images might be:
     {
        “full” : {
            “url” : “http://example.com/f.jpg”
        },
        “thumb” : {
            “url” : “http://example.com/t.jpg”
        }
    }
    This allows you to easily include product images when messaging users with order confirmations and abandoned-cart reminders.
 * Must be a valid JSON object. Invalid objects will be discarded.
 */
@property (strong, nonatomic, nullable) NSDictionary<NSString *, id> *images;

- (nullable instancetype) init NS_UNAVAILABLE;
+ (nullable instancetype) new NS_UNAVAILABLE;

/**
 * Create a purchase item instance with the required fields.
 *
 * @param quantity The quantity of the item.
 * @param title    The title of the item. Must not be nil.
 * @param price    The cost of a single item in cents.
 * @param ID       Your identifier for the item.
 * @param URL      The URL for the item. Must not be nil.
 * @return CarnivalPurchaseItem instance. Will return nil if nil parameters are passed.
 */
- (nullable instancetype)initWithQuantity:(NSUInteger)quantity
                                    title:(NSString *)title
                                    price:(NSUInteger)price
                                   itemId:(NSString *)ID
                                  itemUrl:(NSURL *)URL;

/**
 * Create a purchase item instance with the supplied content item and quantity.
 *
 * @param contentItem The content item representing the item being purchased.
 * @return CarnivalPurchaseItem instance. Will return nil if nil parameters are passed.
 */
- (nullable instancetype)initWithContentItem:(CarnivalContentItem *)contentItem;

/**
 * Add a tag to the purchase item.
 *
 * @param tag the tag to add.
 */
- (void)addTag:(NSString *)tag;

/**
 * Add a custom key value pair to the purchase item.
 * @discussion Adds a custom key value pair. The value must be valid for JSON serialization.
 *
 * @param key the custom value key
 * @param value the custom value
 */
- (void)addVarWithKey:(NSString *)key value:(id)value;

/**
 * Sets the URL to use for the full item image.
 *
 * @param url the URL for the full image.
 */
- (void)setFullImageUrl:(NSURL *)url;

/**
 * Sets the URL to use for the thumb item image.
 *
 * @param url the URL for the thumb image.
 */
- (void)setThumbImageUrl:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
