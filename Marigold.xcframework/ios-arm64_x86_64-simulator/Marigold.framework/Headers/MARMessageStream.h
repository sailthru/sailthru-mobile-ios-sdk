//
//  MARMessageStream.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import <Marigold/MARMessage.h>
#import <Marigold/MARInAppPresentationDecision.h>

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
 *  @deprecated Use prepareInAppNotificationForMessage:requestID:completion: instead.
 *  Complete immediately for a synchronous decision. This callback remains the fallback
 *  when the replacement is not implemented.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the notification should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of in-app notifications.
 */
- (BOOL)shouldPresentInAppNotificationForMessage:(MARMessage *)message
    DEPRECATED_MSG_ATTRIBUTE("Use prepareInAppNotificationForMessage:requestID:completion: instead; complete immediately for synchronous decisions.");

/**
 * Asks the delegate to prepare an in-app notification without blocking the UI thread.
 * Replaces shouldPresentInAppNotificationForMessage: for synchronous or asynchronous
 * decisions. This method takes precedence when implemented.
 *
 * Called on the main thread once for an eligible presentation target. requestID uniquely
 * identifies this attempt (including repeated attempts for the same message). Return a
 * decision through completion immediately or later, from any thread. Only the first
 * response is accepted. Responses after cancellation or the deadline are ignored.
 *
 * The deadline is two seconds. If no decision arrives, the SDK displays its default UI.
 * Return suppress or handled within the deadline to prevent default presentation.
 * No impression is recorded by the SDK for either of those decisions; a custom renderer
 * owns its own impression registration. Showing and dismissal lifecycle events remain
 * notifications and do not wait for a response.
 *
 * The application must retain its delegate. Setting the delegate to nil, disabling
 * notifications, hiding the target window, or deactivating its scene cancels pending work.
 */
- (void)prepareInAppNotificationForMessage:(MARMessage *)message
                               requestID:(NSString *)requestID
                              completion:(void (^)(MARInAppPresentationDecision *decision))completion
    NS_SWIFT_NAME(prepareInAppNotification(for:requestID:completion:));

/**
 *  Asks the delegate whether to show the Full Screen Message Detail screen for a given message.
 *
 *  @deprecated Use prepareMessageDetailForMessage:requestID:completion: instead.
 *  Complete immediately for a synchronous decision. This callback remains the fallback
 *  when the replacement is not implemented.
 *
 *  @param message The message that SDK wishes to present an In App notification for.
 *
 *  @return A boolean of whether or not the Full Screen Message Detail screen should be presented internally by the Sailthru Mobile SDK. Override and return NO if the host app would like to handle the rendering and presentation of full screen messages.
 */
- (BOOL)shouldPresentMessageDetailForMessage:(MARMessage *)message
    DEPRECATED_MSG_ATTRIBUTE("Use prepareMessageDetailForMessage:requestID:completion: instead; complete immediately for synchronous decisions.");

/**
 * Prepares a full-screen message detail presentation without blocking the UI thread.
 * Replaces shouldPresentMessageDetailForMessage: for synchronous or asynchronous
 * decisions and takes precedence when implemented.
 * Called on the main thread; complete immediately or later, from any thread, using
 * display (optionally with local configuration), suppress, or handled.
 *
 * requestID uniquely identifies this attempt. Only the first response is accepted.
 * The deadline is two seconds; an unanswered request uses the default presentation and app defaults.
 * Late replies are ignored after the deadline, delegate replacement/removal, dismissal,
 * window hiding, scene deactivation, backgrounding, or a newer request in the same window.
 * Suppressed/app-handled attempts create no SDK detail view or detail impression.
 * A custom renderer owns its impression registration. Retain the delegate yourself.
 *
 * Manual detail presentation remains available when automatic in-app notifications
 * are disabled. Per-message configuration styles the native frame and controls;
 * campaign HTML keeps its own styling. Lifecycle events are delivered as notifications.
 */
- (void)prepareMessageDetailForMessage:(MARMessage *)message
                           requestID:(NSString *)requestID
                          completion:(void (^)(MARInAppPresentationDecision *decision))completion
    NS_SWIFT_NAME(prepareMessageDetail(for:requestID:completion:));

@end

@interface MARMessageStream : NSObject

/**
 * App-wide local UI defaults, shared by all MARMessageStream instances. Both setting
 * and reading take a deep copy; nil resets to SDK defaults. Per-message configuration
 * in a display decision overrides these defaults field by field. Configure at SDK setup.
 */
@property (nullable, nonatomic, copy) MARInAppPresentationDefaults *presentationDefaults;

/**
 * App-wide font aliases for message title and body font names. Register at app startup.
 * Values are base UIFonts; each message can specify its font size and an optional weight.
 * Registered aliases take priority over installed font names. Blank names are ignored.
 * The dictionary is copied on input/access. Replacements affect future presentations only.
 * Fonts are never downloaded or injected into campaign HTML. Nil/empty clears the aliases.
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, UIFont *> *presentationFonts;

/** @name Message statistics */

/**
 *  Asynchronously returns the total number of unread messages in the message stream.
 *
 *  @param completionBlock A block object which returns the number of unread messages when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the completionBlock is NULL.
 */
- (void)unreadCount:(void (^)(NSUInteger unreadCount, NSError *__nullable error))completionBlock;

/**
 *  Asynchronously marks a given message as read.
 *
 *  @param completionBlock A block object which returns an error which will be non-nil if there was a problem marking the message as read.
 */
- (void)markMessageAsRead:(MARMessage *)message withResponse:(nullable void(^)(NSError *__nullable error))completionBlock;

/**
 *  Asynchronously marks a given array of messages as read.
 *
 *  @param completionBlock A block object which returns an error which will be non-nil if there was a problem marking the messages as read.
 */
- (void)markMessagesAsRead:(NSArray<MARMessage *> *)messages withResponse:(nullable void(^)(NSError *__nullable error))completionBlock;

/**
 *  Returns the message associated with the provided messageId.
 *
 *  @param messageId The ID of the message to retrieve.
 *  @param block A block which gets called with the MARMessage object and a possible error. Cannot be NULL.
 */
- (void)messageFor:(NSString *)messageId withCompletion:(void (^)(MARMessage *__nullable message, NSError *__nullable error))block;

/**
 *  Returns an array of MARMessages for the device.
 *
 *  @param completionBlock A block which gets called with an array of MARMessage objects and a possbile error. Cannot be NULL.
 */
- (void)messages:(void (^)(NSArray<MARMessage *> *__nullable messages, NSError *__nullable error))completionBlock;

/**
 *  Removes the message with the given messageID from the Message Stream
 *
 *  @param message The message to be removed.
 *  @param completionBlock A block object which returns an error which will be non-nil if there was a problem removing the message.
 */
- (void)removeMessage:(MARMessage *)message withResponse:(nullable void (^)(NSError *__nullable error))completionBlock;

/**
 * Clear the Message Stream for the device.
 * @param completionBlock A block object which returns an error which will be non-nil if there was a problem clearing the message stream.
 */
- (void)clearMessagesWithResponse:(nullable void(^)(NSError *__nullable error))completionBlock;

/**
 *  Sets the delegate for the MARMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the MARMessageStream.
 */
- (void)setDelegate:(nullable id<MARMessageStreamDelegate>)delegate;

/** Clears the delegate only if it is still the registered delegate. */
- (void)removeDelegateIfCurrent:(id<MARMessageStreamDelegate>)delegate;

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
