//
//  CarnivalAttributes.h
//  Carnival
//
//  Created by Sam Jarman on 4/21/16.
//  Copyright © 2016 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CarnivalAttributesMergeRule) {
    CarnivalAttributesMergeRuleUpdate,
    CarnivalAttributesMergeRuleReplace
};

/**
 *  Use this class to construct an object which you can then pass to the setAttributes: method. You can set as many objects with keys as you like.
 *  Attributes can update existing attributes set (merge) or can completely replace them with a new set. Use the setAttributesMergeRule for this. The default behaviour is merge.
 *  Null values will remove the value for the given key.
 *  To completly clear all values, set a newly instantiated CarnivalAttributes object with the merge sule set to CarnivalAttributesMergeRuleReplace.
 */
@interface CarnivalAttributes : NSObject

/**
 *  Sets a string object for a given key. The key must not be nil.
 *
 *  @param string The string to set.
 *  @param key The key to set.
 */
- (void)setString:(nullable NSString *)string forKey:(nonnull NSString *)key;

/**
 *  Sets an array of string objects for a given key. All items in the array must be of type NSString. The key must not be nil.
 *
 *  @param strings The array of strings to set.
 *  @param key The key to set.
 */
- (void)setStrings:(nullable NSArray<NSString *> *)strings forKey:(nonnull NSString *)key;

/**
 *  Sets a date objects for a given key. The key must not be nil.
 *
 *  @param date The date to set.
 *  @param key The key to set.
 */
- (void)setDate:(nullable NSDate *)date forKey:(nonnull NSString *)key;

/**
 *  Sets an array of date objects for a given key. All items in the array must be of type NSDate. The key must not be nil.
 *
 *  @param dates The array of dates to set.
 *  @param key The key to set.
 */
- (void)setDates:(nullable NSArray<NSDate *> *)dates forKey:(nonnull NSString *)key;

/**
 *  Sets an integer object for a given key. The key must not be nil.
 *
 *  @param integer The integer to set.
 *  @param key The key to set.
 */
- (void)setInteger:(NSInteger)integer forKey:(nonnull NSString *)key;


/**
 *  Sets an array of integers objects for a given key. All items in the array must be of type NSNumber (constructed with an NSInteger). The key must not be nil.
 *
 *  @param integers The array of integers to set.
 *  @param key The key to set.
 */
- (void)setIntegers:(nullable NSArray<NSNumber *> *)integers forKey:(nonnull NSString *)key;

/**
 *  Sets a boolean object for a given key. The key must not be nil.
 *
 *  @param aBool The boolean to set.
 *  @param key The key to set.
 */
- (void)setBool:(BOOL)aBool forKey:(nonnull NSString *)key;

/**
 *  Sets a float object for a given key. The key must not be nil.
 *
 *  @param aFloat The float to set.
 *  @param key The key to set.
 */
- (void)setFloat:(CGFloat)aFloat forKey:(nonnull NSString *)key;

/**
 *  Sets an array of floats objects for a given key. All items in the array must be of type NSNumber (constructed with a CGFloat). The key must not be nil.
 *
 *  @param floats The array of floats to set.
 *  @param key The key to set.
 */
- (void)setFloats:(nullable NSArray<NSNumber *> *)floats forKey:(nonnull NSString *)key;

/**
 *  Sets the method of merging on the attributes. CarnivalAttributesMergeRuleUpdate will merge with existing attributes and CarnivalAttributesMergeRuleReplace will replace all data with the new set.
 *
 *  @param mergeRule The CarnivalAttributesMergeRule to use. The default is update.
 */
- (void)setAttributesMergeRule:(CarnivalAttributesMergeRule)mergeRule;

@end
