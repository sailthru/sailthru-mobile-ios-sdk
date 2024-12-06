//
//  MARAttributes.h
//  Sailthru Mobile
//
//  Created by Ian Stewart on 28/11/2024.
//  Copyright © 2024 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MARAttributesMergeRule) {
    MARAttributesMergeRuleUpdate,
    MARAttributesMergeRuleReplace
};

@interface MARAttributes : NSObject

/**
 *  Sets a string object for a given key. The key must not be nil.
 *
 *  @param string The string to set.
 *  @param key The key to set.
 */
- (void)setString:(nullable NSString *)string forKey:(nonnull NSString *)key;

/**
 * Gets a string object for the given key, or nil if the key isn't present or isn't a string type. The key must not be nil.
 */
- (nullable NSString *)getString:(nonnull NSString *)key;

/**
 *  Sets an array of string objects for a given key. All items in the array must be of type NSString. The key must not be nil.
 *
 *  @param strings The array of strings to set.
 *  @param key The key to set.
 */
- (void)setStrings:(nullable NSArray<NSString *> *)strings forKey:(nonnull NSString *)key;

/**
 * Gets a string array object for the given key, or nil if the key isn't present or isn't a string array type. The key must not be nil.
 */
- (nullable NSArray<NSString *> *)getStrings:(nonnull NSString *)key;

/**
 *  Sets a date objects for a given key. The key must not be nil.
 *
 *  @param date The date to set.
 *  @param key The key to set.
 */
- (void)setDate:(nullable NSDate *)date forKey:(nonnull NSString *)key;

/**
 * Gets a date object for the given key, or nil if the key isn't present or isn't a date type. The key must not be nil.
 */
- (nullable NSDate *)getDate:(nonnull NSString *)key;

/**
 *  Sets an array of date objects for a given key. All items in the array must be of type NSDate. The key must not be nil.
 *
 *  @param dates The array of dates to set.
 *  @param key The key to set.
 */
- (void)setDates:(nullable NSArray<NSDate *> *)dates forKey:(nonnull NSString *)key;

/**
 * Gets a date array object for the given key, or nil if the key isn't present or isn't a date array type. The key must not be nil.
 */
- (nullable NSArray<NSDate *> *)getDates:(nonnull NSString *)key;

/**
 *  Sets an integer object for a given key. The key must not be nil.
 *
 *  @param integer The integer to set.
 *  @param key The key to set.
 */
- (void)setInteger:(NSInteger)integer forKey:(nonnull NSString *)key;

/**
 * Gets an integer value for the given key, or the default value if the key isn't present or isn't an integer type. The key must not be nil.
 */
- (NSInteger)getInteger:(nonnull NSString *)key defaultValue:(NSInteger) defaultValue;

/**
 *  Sets an array of integers objects for a given key. All items in the array must be of type NSNumber (constructed with an NSInteger). The key must not be nil.
 *
 *  @param integers The array of integers to set.
 *  @param key The key to set.
 */
- (void)setIntegers:(nullable NSArray<NSNumber *> *)integers forKey:(nonnull NSString *)key;

/**
 * Gets an integer array object for the given key, or nil if the key isn't present or isn't an integer array type. The key must not be nil.
 */
- (nullable NSArray<NSNumber *> *)getIntegers:(nonnull NSString *)key;

/**
 *  Sets a boolean object for a given key. The key must not be nil.
 *
 *  @param aBool The boolean to set.
 *  @param key The key to set.
 */
- (void)setBool:(BOOL)aBool forKey:(nonnull NSString *)key;

/**
 * Gets a boolean value for the given key, or the default value if the key isn't present or isn't a boolean type. The key must not be nil.
 */
- (BOOL)getBool:(nonnull NSString *)key defaultValue:(BOOL)defaultValue;

/**
 *  Sets a float object for a given key. The key must not be nil.
 *
 *  @param aFloat The float to set.
 *  @param key The key to set.
 */
- (void)setFloat:(CGFloat)aFloat forKey:(nonnull NSString *)key;

/**
 * Gets a float value for the given key, or the default value if the key isn't present or isn't a float type. The key must not be nil.
 */
- (CGFloat)getFloat:(nonnull NSString *)key defaultValue:(CGFloat)defaultValue;

/**
 *  Sets an array of floats objects for a given key. All items in the array must be of type NSNumber (constructed with a CGFloat). The key must not be nil.
 *
 *  @param floats The array of floats to set.
 *  @param key The key to set.
 */
- (void)setFloats:(nullable NSArray<NSNumber *> *)floats forKey:(nonnull NSString *)key;

/**
 * Gets a float array object for the given key, or nil if the key isn't present or isn't a float array type. The key must not be nil.
 */
- (nullable NSArray<NSNumber *> *)getFloats:(nonnull NSString *)key;

/**
 *  Sets the method of merging on the attributes. MARAttributesMergeRuleUpdate will merge with existing attributes and MARAttributesMergeRuleReplace will replace all data with the new set.
 *
 *  @param mergeRule The MARAttributesMergeRule to use. The default is update.
 */
- (void)setAttributesMergeRule:(MARAttributesMergeRule)mergeRule;

/**
 * Get the merge rules for these attributes.
 */
- (MARAttributesMergeRule)getAttributesMergeRule;

@end

NS_ASSUME_NONNULL_END
