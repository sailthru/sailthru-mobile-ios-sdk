//
//  EngageBySailthru.h
//  Sailthru Mobile
//
//  Created by Angelo Esquibel on 12/4/23.
//  Copyright © 2023 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface EngageBySailthru : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * Create a new instance of the EngageBySailthru class. Returns an error if `startEngine` has not been called
 * or if the EngageBySailthru functionality is not available.
 */
- (instancetype _Nullable)initWithError:(NSError **)error NS_SWIFT_NAME(init());

/**
 * Enables AutoAnalytics tracking for a given array of event sources. This is opt-in as of Sailthru Mobile 5.0.0.
 *
 * @param enableArray - An array of const strings beginning with MARAutoAnalyticsSource.
 */
- (void)enableAutoAnalytics:(NSArray<NSString *> *)enableArray;

/** @name Custom Attributes */

/**
 *  Asyncronously sets a MARAttributes object with Sailthru Mobile.
 *
 *  @param attributes A nonnull MARAttributes object with the desired attributes set.
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)setAttributes:(MARAttributes *)attributes withResponse:(nullable void(^)(NSError *__nullable error))block __deprecated_msg("use setProfileVars:withResponse: instead");

/**
 *  Asyncronously removes a value for a given key.
 *
 *  @param key The string value of the key.
 *  @param block The block returned from the asynchronous call. May contain an error.
 **/
- (void)removeAttributeWithKey:(NSString *)key withResponse:(nullable void(^)(NSError *__nullable error))block __deprecated_msg("use setProfileVars:withResponse: instead");

/**
 *  Asyncronously clears the Attribute data from the device.
 *  Use this method to clear the device attributes after user logout.
 *
 *  @param block The block returned from the asynchronous call. May contain an error.
 **/

- (void)clearAttributesWithResponse:(nullable void(^)(NSError *__nullable error))block __deprecated_msg("use setProfileVars:withResponse: instead");

/** @name Sailthru Link Handling */

/**
 * If you're using Sailthru email combined with universal links, your application will open with an encoded Sailthru 'link' url.
 * This method will decode the link URL and return its destination URL, as well as making sure that the clickthrough metrics for this link are correctly attributed in Sailthru.
 * This method should be called from your AppDelegate's `application:continueUserActivity:restorationHandler:` method.
 *
 * @param url the Sailthru Link to be unrolled
 * @return the destination that the Sailthru link points to, or nil if the link isn't a valid Sailthru Link.
 */
- (NSURL * _Nullable)handleSailthruLink:(NSURL *)url;

/** @name Events */

/**
 *  Logs a custom event with the given name.
 *
 *  @param name The name of the custom event to be logged.
 */
- (void)logEvent:(NSString *)name;

/**
 *  Logs a custom event with the given name and associated vars.
 *
 *  @param name The name of the custom event to be logged.
 *  @param vars The associated variables for the event.
 */
- (void)logEvent:(NSString *)name withVars:(NSDictionary<NSString *, id> *__nullable)vars;

/**
 * Clear the custom events from the device data.
 * @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)clearEventsWithResponse:(nullable void(^)(NSError *__nullable error))block;

/** @name Users */

/**
 *  Sets a user email for the device.
 *
 *  @param userEmail The email of the user to be set.
 *
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)setUserEmail:(nullable NSString *)userEmail withResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Sets a user ID for the device.
 *
 *  @param userId The ID of the user to be set.
 *
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)setUserId:(nullable NSString *)userId withResponse:(nullable void(^)(NSError *__nullable error))block;

/** @name Tracking */

/**
 *  Registers that the given pageview with Sailthru SPM.
 *
 *  @param url The URL of the content we're tracking a view of. Must be a valid URL with protocol http:// or https:// -
 *          this generally should correspond to the web link of the content being tracked, and the stored URL in the Sailthru content collection
 *  @param tags Tags for this content
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)trackPageviewWithUrl:(NSURL *)url andTags:(NSArray<NSString *> *)tags andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers that the given pageview with Sailthru SPM.
 *
 *  @param url The URL of the content we're tracking a view of. Must be a valid URL with protocol http:// or https:// -
 *              this generally should correspond to the web link of the content being tracked, and the stored URL in the Sailthru content collection
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)trackPageviewWithUrl:(NSURL *)url andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers an impression - a reasonable expectation that a user has seen a piece of content - with Sailthru SPM.
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being viewed
 *  @param urls a List of the URLs of the items contained within this section. Useful if multiple items
 *             of content are contained within a section, otherwise just pass a single-item array.
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)trackImpressionWithSection:(NSString *)sectionID andUrls:(NSArray<NSURL *> *)urls andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Registers an impression - a reasonable expectation that a user has seen a piece of content - with Sailthru SPM.
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being viewed
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)trackImpressionWithSection:(NSString *)sectionID andResponse:(nullable void(^)(NSError *__nullable error))block;

/**
 *  Tracks with Sailthru SPM that a section has been tapped on, transitioning the user to a detail view
 *
 *  @param sectionID the Section ID on Sailthru SPM corresponding to the section being tapped
 *  @param url the URL of the detail being transitioned to
 *  @param block The block returned from the asynchronous call. May contain an error.
 */
- (void)trackClickWithSection:(NSString *)sectionID andUrl:(NSURL *)url andResponse:(nullable void(^)(NSError *__nullable error))block;

/** @name Profile Vars*/

/**
 *  Sets the profile vars on the server.
 *
 *  @param vars the vars to set on the server.
 *  @param block the block returned from the asynchronous call. May contain an error.
 */
- (void)setProfileVars:(NSDictionary<NSString *, id> *)vars withResponse:(nullable void(^)(NSError * _Nullable))block;

/**
 *  Retrieves the profile vars from the server.
 *
 *  @param block the block returned from the asynchronous call. May contain an error.
 */
- (void)getProfileVarsWithResponse:(nullable void(^)(NSDictionary<NSString *, id> * _Nullable, NSError * _Nullable))block;

/** @name Purchases*/

/**
 * Logs a purchase with Sailthru platform. This can be used for mobile purchase attribution.
 *
 * @param purchase The purchase to log with the platform.
 * @param block The block to handle the result of the call. May contain an error if the call failed.
 */
- (void)logPurchase:(MARPurchase *)purchase withResponse:(nullable void(^)(NSError * _Nullable))block;

/**
 * Logs a cart abandonment with the Sailthru platform. Use this to initiate cart abandoned flows.
 *
 * @param purchase The abandoned purchase to log with the platform.
 * @param block The block to handle the result of the call. May contain an error if the call failed.
 */
- (void)logAbandonedCart:(MARPurchase *)purchase withResponse:(nullable void(^)(NSError * _Nullable))block;

@end

NS_ASSUME_NONNULL_END
