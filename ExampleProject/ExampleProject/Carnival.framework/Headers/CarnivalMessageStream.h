//
//  CarnivalStream.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2017 Carnival.io. All rights reserved.
//
//  For documentation see http://docs.mobile.sailthru.com
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CarnivalMessage.h"


NS_ASSUME_NONNULL_BEGIN
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
NS_ASSUME_NONNULL_END

typedef NS_ENUM(NSInteger, CarnivalImpressionType) {
    CarnivalImpressionTypeInAppNotificationView,
    CarnivalImpressionTypeStreamView,
    CarnivalImpressionTypeDetailView
};

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
 *  @return A boolean of whether or not the notification should be presented internally by the Carnival SDK. Override and return NO if the host app would like to handle the rendering and presentation of in-app notifications.
 */
- (BOOL)shouldPresentInAppNotificationForMessage:(nonnull CarnivalMessage *)message;

/**
 *  Asks the delegate whether to show the Full Screen Message Detail screen for a given message.
 *
 *  @param message The message that Carnival wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the Full Screen Message Detail screen should be presented internally by the Carnival SDK. Override and return NO if the host app would like to handle the rendering and presentation of full screen messages.
 */
- (BOOL)shouldPresentMessageDetailForMessage:(nonnull CarnivalMessage *)message;

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
+ (void)unreadCount:(nonnull void (^)(NSUInteger unreadCount, NSError *__nullable error))handler;

/**
 *  Asynchronously marks a given message as read.
 *
 *  @param handler A block object which returns an error which will be non-nil if there was a problem marking the message as read.
 */
+ (void)markMessageAsRead:(nonnull CarnivalMessage *)message withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Asynchronously marks a given array of messages as read.
 *
 *  @param handler A block object which returns an error which will be non-nil if there was a problem marking the messages as read.
 */
+ (void)markMessagesAsRead:(nonnull NSArray<CarnivalMessage *> *)messages withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Returns an array of Carnival Messages for the device.
 *
 *  @param block A block which gets called with an array of CarnivalMessage objects and a possbile error. Cannot be NULL.
 */
+ (void)messages:(nonnull void (^)(NSArray<CarnivalMessage *> *__nullable messages, NSError *__nullable error))block;

/**
 *  Removes the message with the given messageID from the Carnival Message Stream
 *
 *  @param message The message to be removed.
 *  @param handler A block object which returns an error which will be non-nil if there was a problem removing the message.
 */
+ (void)removeMessage:(nonnull CarnivalMessage *)message withResponse:(nullable void (^)(NSError *__nullable error))handler;

/**
 *  Sets the delegate for the CarnivalMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the CarnivalMessageStream.
 */
+ (void)setDelegate:(nonnull id<CarnivalMessageStreamDelegate>)delegate;

/**
 * Shows the message detail screen for a given message
 * @note if you support multiple windows, use the presentMessageDetailForMessage:inWindow: method instead to specify the window to show the detail in.
 *
 * @param message The Message you wish to present.
 **/
+ (void)presentMessageDetailForMessage:(nonnull CarnivalMessage *)message;

/**
 * Shows the message detail screen for a given message in the provided window.
 *
 * @param message The Message you wish to present.
 * @param window The window to display the message detail in. Use in iOS 13+ if you utilitse multiple UIScenes to ensure the detail is displayed in the correct scene.
 */
+ (void)presentMessageDetailForMessage:(nonnull CarnivalMessage *)message inWindow:(nonnull UIWindow *)window;

/**
 * Dismisses the message detail screen.
 *
 * This method will remove all displayed message details screens from the UI.
 * @note If you are using multiple windows this will dismiss details screens from all windows. If you want to remove one at a time use the dismissMessageDetailForWindow: method.
 */
+ (void)dismissMessageDetail;

/**
 * Dismisses the message details screen from the specified window.
 *
 * @param window The window containing the message details.
 */
+ (void)dismissMessageDetailForWindow:(nonnull UIWindow *)window;

/**
 *  Creates an impression for a message for a given interaction type.
 *
 *  @param impressionType the CarnivalImpressionType type of the impression.
 *
 *  @param message the CarnivalMessage message on which you wish to create the impression.
 */
+ (void)registerImpressionWithType:(CarnivalImpressionType)impressionType forMessage:(nonnull CarnivalMessage *)message;

@end
