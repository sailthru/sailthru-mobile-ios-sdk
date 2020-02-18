//
//  STMMessageStream.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "CarnivalMessageStream.h"
#import "STMMessage.h"

NS_ASSUME_NONNULL_BEGIN

// Notifications
extern NSString * const STMMessageStreamWillShowMessageDetailNotification;
extern NSString * const STMMessageStreamDidShowMessageDetailNotification;
extern NSString * const STMMessageStreamWillDismissMessageDetailNotification;
extern NSString * const STMMessageStreamDidDismissMessageDetailNotification;

extern NSString * const STMMessageStreamWillShowInAppNotificationNotification;
extern NSString * const STMMessageStreamDidShowInAppNotificationNotification;
extern NSString * const STMMessageStreamWillDismissInAppNotificationNotification;
extern NSString * const STMMessageStreamDidDismissInAppNotificationNotification;

extern NSString * const STMMessageStreamUnreadMessageCountDidChangeNotification;

// Keys
extern NSString * const STMMessageStreamUnreadCountKey;
extern NSString * const STMMessageTypeKey;
extern NSString * const STMMessageIDKey;

typedef NS_ENUM(NSInteger, STMImpressionType) {
    STMImpressionTypeInAppNotificationView,
    STMImpressionTypeStreamView,
    STMImpressionTypeDetailView
};

@protocol STMMessageStreamDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the STMMessageStream will show the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be displayed.
 */
- (void)willShowMessageOfType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream showed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was displayed.
 */
- (void)didShowMessageOfType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream will dismiss the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be dismissed.
 */
- (void)willDismissMessageOfType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream dismissed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was dismissed.
 */
- (void)didDismissMessageOfType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream will show an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be shown.
 */
- (void)willShowInAppNotificationForMessageType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream showed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was shown.
 */
- (void)didShowInAppNotificationForMessageType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream will dismiss an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be dismissed.
 */
- (void)willDismissInAppNotificationForMessageType:(STMMessageType)messageType;

/**
 *  Tells the delegate that the STMMessageStream dismissed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was dismissed.
 */
- (void)didDismissInAppNotificationForMessageType:(STMMessageType)messageType;

/**
 *  Asks the delegate whether to show the In App notification for a given message.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the notification should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of in-app notifications.
 */
- (BOOL)shouldPresentInAppNotificationForMessage:(STMMessage *)message;

/**
 *  Asks the delegate whether to show the Full Screen Message Detail screen for a given message.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the Full Screen Message Detail screen should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of full screen messages.
 */
- (BOOL)shouldPresentMessageDetailForMessage:(STMMessage *)message;

@end

@interface STMMessageStream : NSObject

/** @name Message statistics */

/**
 *  Asynchronously returns the total number of unread messages in the message stream.
 *
 *  @param handler A block object which returns the number of unread messages when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the handler block is NULL.
 */
- (void)unreadCount:(void (^)(NSUInteger unreadCount, NSError *__nullable error))handler;

/**
 *  Asynchronously marks a given message as read.
 *
 *  @param handler A block object which returns an error which will be non-nil if there was a problem marking the message as read.
 */
- (void)markMessageAsRead:(STMMessage *)message withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Asynchronously marks a given array of messages as read.
 *
 *  @param handler A block object which returns an error which will be non-nil if there was a problem marking the messages as read.
 */
- (void)markMessagesAsRead:(NSArray<STMMessage *> *)messages withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Returns an array of STMMessages for the device.
 *
 *  @param block A block which gets called with an array of STMMessage objects and a possbile error. Cannot be NULL.
 */
- (void)messages:(void (^)(NSArray<STMMessage *> *__nullable messages, NSError *__nullable error))block;

/**
 *  Removes the message with the given messageID from the Message Stream
 *
 *  @param message The message to be removed.
 *  @param handler A block object which returns an error which will be non-nil if there was a problem removing the message.
 */
- (void)removeMessage:(STMMessage *)message withResponse:(nullable void (^)(NSError *__nullable error))handler;

/**
 *  Sets the delegate for the STMMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the STMMessageStream.
 */
- (void)setDelegate:(id<STMMessageStreamDelegate>)delegate;

/**
 * Shows the message detail screen for a given message
 * @note if you support multiple windows, use the presentMessageDetailForMessage:inWindow: method instead to specify the window to show the detail in.
 *
 * @param message The Message you wish to present.
 **/
- (void)presentMessageDetailForMessage:(STMMessage *)message;

/**
 * Shows the message detail screen for a given message in the provided window.
 *
 * @param message The Message you wish to present.
 * @param window The window to display the message detail in. Use in iOS 13+ if you utilitse multiple UIScenes to ensure the detail is displayed in the correct scene.
 */
- (void)presentMessageDetailForMessage:(STMMessage *)message inWindow:(UIWindow *)window;

/**
 * Dismisses the message detail screen.
 *
 * This method will remove all displayed message details screens from the UI.
 * @note If you are using multiple windows this will dismiss details screens from all windows. If you want to remove one at a time use the dismissMessageDetailForWindow: method.
 */
- (void)dismissMessageDetail;

/**
 * Dismisses the message details screen from the specified window.
 *
 * @param window The window containing the message details.
 */
- (void)dismissMessageDetailForWindow:(UIWindow *)window;

/**
 *  Creates an impression for a message for a given interaction type.
 *
 *  @param impressionType the STMImpressionType type of the impression.
 *
 *  @param message the STMMessage message on which you wish to create the impression.
 */
- (void)registerImpressionWithType:(STMImpressionType)impressionType forMessage:(STMMessage *)message;

@end

NS_ASSUME_NONNULL_END
