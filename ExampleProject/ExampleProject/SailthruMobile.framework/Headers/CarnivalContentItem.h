//
//  CarnivalContentItem.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2017 Carnival.io. All rights reserved.
//

#import <Foundation/Foundation.h>

__attribute__ ((deprecated("use STMContentItem class in SailthruMobile framework instead")))
@interface CarnivalContentItem : NSObject

/**
 * The unique ID of the content item.
 */
@property (nonatomic, strong, nonnull)  NSString *contentItemID;

/**
 * The unique ID of the content item's url.
 */
@property (nonatomic, strong, nonnull)  NSString *contentItemHashID;

/**
 * The title of the content item.
 */
@property (nonatomic, strong, nonnull)  NSString *title;

/**
 * The description of the content item.
 */
@property (nonatomic, strong, nullable) NSString *contentItemDescription;

/**
 * The amount of views of the content item.
 */
@property (nonatomic, strong, nullable)  NSNumber *views;

/**
 * The URL for the location of the content item.
 */
@property (nonatomic, strong, nonnull)  NSURL *URL;

/**
 * The URL of image associated with content item.
 */
@property (nonatomic, strong, nullable) NSURL *imageURL;

/**
 * The URL of the thumbnail image associated with content item.
 */
@property (nonatomic, strong, nullable) NSURL *imageThumbURL;

/**
 * The URL of the full size image associated with content item.
 */
@property (nonatomic, strong, nullable) NSURL *imageFullURL;

/**
 * A dictionary of all image sizes and URLs of images associated with content item.
 */
@property (nonatomic, strong, nullable) NSDictionary *images;

/**
 * The date the content was created, if applicable.
 */
@property (nonatomic, strong, nullable) NSDate *date;

/**
 * The tags associated with the content item.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *>* tags;

/**
 * The vars associated with the content item.
 */
@property (nonatomic, strong, nullable) NSDictionary *vars;

/**
 * The date the content expires, if applicable.
 */
@property (nonatomic, strong, nullable) NSDate *expireDate;

/**
 * Any additional fields associated with the content item's data.
 */
@property (nonatomic, strong, nullable) NSDictionary *extraFields;


/* Media Items properties */

/**
 * The author of the content item, if applicable.
 */
@property (nonatomic, strong, nullable)  NSString *author;

/**
 * The location of the content item's origin.
 */
@property (nonatomic, strong, nullable)  NSString *location;


/* Ecommerce Items properties */

/**
 * The stock keeping unit of the content item.
 */
@property (nonatomic, strong, nullable)  NSString *SKU;

/**
 * The amount of inventory of the item.
 */
@property (nonatomic, strong, nullable)  NSNumber *inventory;

/**
 * The name of the site the item comes from.
 */
@property (nonatomic, strong, nullable)  NSString *siteName;

/**
 * The price of the content item.
 */
@property (nonatomic, strong, nullable) NSNumber *price;

/**
 * The purchase quantity of the content item, if applicable.
 */
@property (nonatomic, strong, nullable) NSNumber *purchaseQuantity;

@end
