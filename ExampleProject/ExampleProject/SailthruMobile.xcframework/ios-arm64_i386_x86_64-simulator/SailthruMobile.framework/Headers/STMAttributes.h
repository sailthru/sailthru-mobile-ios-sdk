//
//  STMAttributes.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, STMAttributesMergeRule) {
    STMAttributesMergeRuleUpdate,
    STMAttributesMergeRuleReplace
};

@interface STMAttributes : NSObject

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
 *  Sets the method of merging on the attributes. STMAttributesMergeRuleUpdate will merge with existing attributes and STMAttributesMergeRuleReplace will replace all data with the new set.
 *
 *  @param mergeRule The STMAttributesMergeRule to use. The default is update.
 */
- (void)setAttributesMergeRule:(STMAttributesMergeRule)mergeRule;

@end

NS_ASSUME_NONNULL_END
