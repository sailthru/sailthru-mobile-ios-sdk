//
//  CarnivalStream.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CarnivalMessage.h"

// Notifications
extern NSString * const CarnivalMessageStreamWillShowMessageDetailNotification;
extern NSString * const CarnivalMessageStreamDidShowMessageDetailNotification;
extern NSString * const CarnivalMessageStreamWillDismissMessageDetailNotification;
extern NSString * const CarnivalMessageStreamDidDismissMessageDetailNotification;

extern NSString * const CarnivalMessageStreamWillShowInAppNotificationNotification;
extern NSString * const CarnivalMessageStreamDidShowInAppNotificationNotification;
extern NSString * const CarnivalMessageStreamWillDismissInAppNotificationNotification;
extern NSString * const CarnivalMessageStreamDidDismissInAppNotificationNotification;

extern NSString * const CarnivalMessageStreamUnreadMessageCountDidChangeNotification;

// Keys
extern NSString * const CarnivalMessageStreamUnreadCountKey;
extern NSString * const CarnivalMessageTypeKey;
extern NSString * const CarnivalMessageIDKey;

@protocol CarnivalMessageStreamDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the CarnivalMessageStream will show the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be displayed.
 */
- (void)willShowMessageOfType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream showed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was displayed.
 */
- (void)didShowMessageOfType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream will dismiss the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be dismissed.
 */
- (void)willDismissMessageOfType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream dismissed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was dismissed.
 */
- (void)didDismissMessageOfType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream will show an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be shown.
 */
- (void)willShowInAppNotificationForMessageType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream showed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was shown.
 */
- (void)didShowInAppNotificationForMessageType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream will dismiss an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be dismissed.
 */
- (void)willDismissInAppNotificationForMessageType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream dismissed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was dismissed.
 */
- (void)didDismissInAppNotificationForMessageType:(CarnivalMessageType)messageType;

/**
 *  Asks the delegate whether to show the In App notification for a given message.
 *
 *  @param message The message that Carnival wishes to present an In App notification for.
 *  
 *  @return A boolean of whether or the notification should be presented internally by the Carnival SDK. Override and return NO if the host app would like to handle the rendering and presentation of in-app notifications. 
 */
- (BOOL)shouldPresentInAppNotificationForMessage:(CarnivalMessage *)message;

@end

@interface CarnivalMessageStream : NSObject

/** @name Message statistics */

/**
 *  Asynchronously returns the total number of unread messages in the message stream.
 *
 *  @param handler A block object which returns the number of unread messages when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the handler block is NULL.
 */

+ (void)unreadCount:(void (^)(NSUInteger unreadCount, NSError *error))handler;

/**
 *  Returns an array of Carnival Messages for the device.
 *
 *  @param block A block which gets called with an array of CarnivalMessage objects and a possbile error. Cannot be NULL.
 */
+ (void)messages:(void(^)(NSArray *messages, NSError *error))block;

/**
 *  Sets the delegate for the CarnivalMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the CarnivalMessageStream.
 */

+ (void)setDelegate:(id<CarnivalMessageStreamDelegate>)delegate;

/**
 * Shows the message detail screen for a given message
 *
 * @param message The Message you wish to present.
 **/
+ (void)presentMessageDetailForMessage:(CarnivalMessage *)message;

/**
 *  Dismisses the message detail screen
 */
+ (void)dismissMessageDetail;

@end
