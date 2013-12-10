//
//  Carnival.h
//  Carnival
//
//  Created by Adam Jones on 22/02/12.
//  Copyright (c) 2012 Carnival Labs . All rights reserved.
//
//  For documentation see http://docs.corepush.com
//
//  Built 29 August 2012

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#define CARNIVAL_VERSION @"1.43"

@interface Carnival : NSObject


/**
 *  Sets the Carnival appKey credentials for this app.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://www.corepush.com
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is set to on http://www.corepush.com .
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)startEngine:(NSString *)appKey;


/**
 *  Sets the Carnival appKey credentials for this app, and the UIRemoteNotificationType at the same time.
 *
 *  @param appKey The appKey you recieved when setting up your app at http://www.corepush.com
 *  @param types The UIRemoteNotificationType attributes you wish to register this app for as defined in UIApplication.h
 *  see appledocs for more information
 *  @discussion An exception will be raised if you do not set your appKey before you call any other methods.
 *  Make sure your app bundle identifier is the same as whatever it is on http://www.corepush.com .
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)startEngine:(NSString *)appKey andNotificationTypes:(UIRemoteNotificationType)types;


/**
 *  Asyncronously sets the tags for Carnival for this Device.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)setTagsInBackground:(NSArray *)tags withResponse:(void(^)(NSArray *tags, NSError *error))block;


/** 
 *  Asyncronously sets the tags for Carnival for this Device, with no callback block.
 *
 *  @param tags An array of tags for this device. A nil value or an empty NSArray will clear the tags for this Device.
 *  @discussion Calling this method will overwrite any previously set tags for this Device.
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)setTagsInBackground:(NSArray *)tags;


/**
 *  Asyncronously adds the tag to Carnival for this Device.  If the tag is already registered with Core Push, this method does not add the tag again.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)addTag:(NSString *)tag inBackgroundWithResponse:(void(^)(NSArray *tags, NSError *error))block;


/**
 *  Asyncronously gets the tags for Carnival for this Device.
 *
 *  @param block The block returned from the asyncronous call containing either an NSArray of tags, or an NSError if there was one.
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)getTagsInBackgroundWithResponse:(void(^)(NSArray *tags, NSError *error))block;


/**
 *  Should clear the application badge automatically when the application launches.
 *  Defaults to NO on iOS versions below 5, YES on iOS versions above 5.
 *
 *  Note: on iOS versions below 5 this method does nothing
 */
+ (void)setShouldClearBadgeOnLaunch:(BOOL)shouldClearBadgeOnLaunch;


/**
 *  Starts tracking location for this user, to allow for GEO based filtering from Core Push
 *
 *  Note: on iOS versions below 5 this method does nothing.
 */
+ (void)enableLocationTracking:(BOOL)enable;


/**
 *  Gives access to the location manager
 *
 * Note: on iOS versions below 5 this method always returns nil.
 */
+ (CLLocationManager *)locationManager;

@end
