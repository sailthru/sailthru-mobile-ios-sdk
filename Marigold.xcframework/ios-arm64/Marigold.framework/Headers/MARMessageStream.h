//
//  MARMessageStream.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "MARMessage.h"

NS_ASSUME_NONNULL_BEGIN

// Notifications
extern NSString * const MARMessageStreamWillShowMessageDetailNotification;
extern NSString * const MARMessageStreamDidShowMessageDetailNotification;
extern NSString * const MARMessageStreamWillDismissMessageDetailNotification;
extern NSString * const MARMessageStreamDidDismissMessageDetailNotification;

extern NSString * const MARMessageStreamWillShowInAppNotificationNotification;
extern NSString * const MARMessageStreamDidShowInAppNotificationNotification;
extern NSString * const MARMessageStreamWillDismissInAppNotificationNotification;
extern NSString * const MARMessageStreamDidDismissInAppNotificationNotification;

extern NSString * const MARMessageStreamUnreadMessageCountDidChangeNotification;

// Keys
extern NSString * const MARMessageStreamUnreadCountKey;
extern NSString * const MARMessageTypeKey;
extern NSString * const MARMessageIDKey;

typedef NS_ENUM(NSInteger, MARImpressionType) {
    MARImpressionTypeInAppNotificationView,
    MARImpressionTypeStreamView,
    MARImpressionTypeDetailView
};

@protocol MARMessageStreamDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the MARMessageStream will show the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be displayed.
 */
- (void)willShowMessageOfType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream showed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was displayed.
 */
- (void)didShowMessageOfType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream will dismiss the detail for a particular message type.
 *
 *  @param messageType the type of the message that will be dismissed.
 */
- (void)willDismissMessageOfType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream dismissed the detail for a particular message type.
 *
 *  @param messageType the type of the message that was dismissed.
 */
- (void)didDismissMessageOfType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream will show an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be shown.
 */
- (void)willShowInAppNotificationForMessageType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream showed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was shown.
 */
- (void)didShowInAppNotificationForMessageType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream will dismiss an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that will be dismissed.
 */
- (void)willDismissInAppNotificationForMessageType:(MARMessageType)messageType;

/**
 *  Tells the delegate that the MARMessageStream dismissed an in-app notification for a particular message.
 *
 *  @param messageType The type of the message that was dismissed.
 */
- (void)didDismissInAppNotificationForMessageType:(MARMessageType)messageType;

/**
 *  Asks the delegate whether to show the In App notification for a given message.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the notification should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of in-app notifications.
 */
- (BOOL)shouldPresentInAppNotificationForMessage:(MARMessage *)message;

/**
 *  Asks the delegate whether to show the Full Screen Message Detail screen for a given message.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the Full Screen Message Detail screen should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of full screen messages.
 */
- (BOOL)shouldPresentMessageDetailForMessage:(MARMessage *)message;

@end

@interface MARMessageStream : NSObject

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
- (void)markMessageAsRead:(MARMessage *)message withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Asynchronously marks a given array of messages as read.
 *
 *  @param handler A block object which returns an error which will be non-nil if there was a problem marking the messages as read.
 */
- (void)markMessagesAsRead:(NSArray<MARMessage *> *)messages withResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Returns an array of MARMessages for the device.
 *
 *  @param block A block which gets called with an array of MARMessage objects and a possbile error. Cannot be NULL.
 */
- (void)messages:(void (^)(NSArray<MARMessage *> *__nullable messages, NSError *__nullable error))block;

/**
 *  Removes the message with the given messageID from the Message Stream
 *
 *  @param message The message to be removed.
 *  @param handler A block object which returns an error which will be non-nil if there was a problem removing the message.
 */
- (void)removeMessage:(MARMessage *)message withResponse:(nullable void (^)(NSError *__nullable error))handler;

/**
 * Clear the Message Stream for the device.
 * @param handler A block object which returns an error which will be non-nil if there was a problem clearing the message stream.
 */
- (void)clearMessagesWithResponse:(nullable void(^)(NSError *__nullable error))handler;

/**
 *  Sets the delegate for the MARMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the MARMessageStream.
 */
- (void)setDelegate:(id<MARMessageStreamDelegate>)delegate;

/**
 * Shows the message detail screen for a given message
 * @note if you support multiple windows, use the presentMessageDetailForMessage:inWindow: method instead to specify the window to show the detail in.
 *
 * @param message The Message you wish to present.
 **/
- (void)presentMessageDetailForMessage:(MARMessage *)message;

/**
 * Shows the message detail screen for a given message in the provided window.
 *
 * @param message The Message you wish to present.
 * @param window The window to display the message detail in. Use in iOS 13+ if you utilitse multiple UIScenes to ensure the detail is displayed in the correct scene.
 */
- (void)presentMessageDetailForMessage:(MARMessage *)message inWindow:(UIWindow *)window;

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
 *  @param impressionType the MARImpressionType type of the impression.
 *
 *  @param message the MARMessage message on which you wish to create the impression.
 */
- (void)registerImpressionWithType:(MARImpressionType)impressionType forMessage:(MARMessage *)message;

@end

NS_ASSUME_NONNULL_END
