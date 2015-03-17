//
//  CarnivalStream.h
//  Carnival
//
//  Created by Kup on 18/11/13.
//  Copyright (c) 2013 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Notifications

extern NSString * const CarnivalMessageStreamWillShowStreamNotification;
extern NSString * const CarnivalMessageStreamDidShowStreamNotification;
extern NSString * const CarnivalMessageStreamWillDismissStreamNotification;
extern NSString * const CarnivalMessageStreamDidDismissStreamNotification;

extern NSString * const CarnivalMessageStreamWillShowMessageDetailNotification;
extern NSString * const CarnivalMessageStreamDidShowMessageDetailNotification;
extern NSString * const CarnivalMessageStreamWillDismissMessageDetailNotification;
extern NSString * const CarnivalMessageStreamDidDismissMessageDetailNotification;

extern NSString * const CarnivalMessageStreamWillShowInAppNotificationNotification;
extern NSString * const CarnivalMessageStreamDidShowInAppNotificationNotification;

extern NSString * const CarnivalMessageStreamUnreadMessageCountDidChangeNotification;

// Keys

extern NSString * const CarnivalMessageStreamUnreadCountKey;
extern NSString * const CarnivalMessageTypeKey;

typedef NS_ENUM(NSInteger, CarnivalMessageType) {
    CarnivalMessageTypeText,
    CarnivalMessageTypeImage,
    CarnivalMessageTypeLink,
    CarnivalMessageTypeVideo,
    CarnivalMessageTypeFakeCall,
    CarnivalMessageTypeStandardPush,
    CarnivalMessageTypeOther
};

@protocol CarnivalMessageStreamDelegate <NSObject>

@optional

/**
 *  Tells the delegate that the CarnivalMessageStream will be shown.
 *
 *  @param messageStreamViewController The CarnivalMessageStream UIViewController that will be shown.
 */

- (void)willShowMessageStream:(UIViewController *)messageStreamViewController;

/**
 *  Tells the delegate that the CarnivalMessageStream was shown.
 *
 *  @param messageStreamViewController The CarnivalMessageStream UIViewController that was shown.
 */

- (void)didShowMessageStream:(UIViewController *)messageStreamViewController;

/**
 *  Tells the delegate that the CarnivalMessageStream will show the detail for a particular message.
 *
 *  @param messageDetailViewController The UIViewController for the detail of a particular message that will be shown.
 */

- (void)willShowMessageDetail:(UIViewController *)messageDetailViewController;

/**
 *  Tells the delegate that the CarnivalMessageStream will show the detail for a particular message.
 *
 *  @param messageDetailViewController The UIViewController for the detail of a particular message that will be shown.
 *  @param messageType The type of the message that will be shown.
 */

- (void)willShowMessageDetail:(UIViewController *)messageDetailViewController forMessageType:(CarnivalMessageType)messageType;

/**
 *  Tells the delegate that the CarnivalMessageStream showed the detail for a particular message.
 *
 *  @param messageDetailViewController The UIViewController for the detail of a particular message that was shown.
 */

- (void)didShowMessageDetail:(UIViewController *)messageDetailViewController;

/**
 *  Tells the delegate that the CarnivalMessageStream showed the detail for a particular message.
 *
 *  @param messageDetailViewController The UIViewController for the detail of a particular message that was shown.
 *  @param messageType The type of the message that was shown.
 */

- (void)didShowMessageDetail:(UIViewController *)messageDetailViewController forMessageType:(CarnivalMessageType)messageType;

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

@required

/**
 *  Tells the delegate that the CarnivalMessageStream needs to be shown.
 *
 *  The CarnivalMessageStream needs to be shown when the user interacts with an in-app message or push notification.
 *
 *  @param streamNavigationController The CarnivalMessageStream to be displayed, wrapped in a UINavigationController.
 *  @param applicationState The UIApplicationState at the point when this delegate was triggered. This may be different from the current UIApplicationState. This paramater can be used to display the stream differently if the app is currently in the background.
 */

- (void)carnivalMessageStreamNeedsDisplay:(UINavigationController *)streamNavigationController fromApplicationState:(UIApplicationState)applicationState;

@end

@interface CarnivalMessageStream : NSObject

/** @name Message statistics */

/**
 *  Asynchronously returns the total number of messages in the message stream.
 *
 *  @deprecated use the messagesCounts: method instead.
 *
 *  @param handler A block object which returns either the total number of messages in the message stream when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the handler block is NULL.
 */

+ (void)messagesCount:(void (^)(NSUInteger count, NSError *error))handler __attribute((deprecated("use the messagesCounts: method instead")));

/**
 *  Asynchronously returns the total number of messages and the number of unread messages in the message stream.
 *
 *  Note: If you are wanting to be notified when the unread messages count updates, observe the CarnivalMessageStreamUnreadMessageCountDidChangeNotification notification.
 *
 *  @param handler A block object which returns either the total number of messages in the message stream and the number of unread messages when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the handler block is NULL.
 */

+ (void)messagesCounts:(void (^)(NSUInteger totalMessagesCount, NSUInteger unreadMessagesCount, NSError *error))handler __attribute((deprecated("use the fetchMessageUnreadCountInBackground method instead")));

/**
 *  Asynchronously fetches the number of unread messages in the Carnival Message Stream and when completed fires a CarnivalMessageStreamUnreadMessageCountDidChangeNotification notification with the unread count in the NSNotification's userInfo, under the CarnivalMessageStreamUnreadCountKey key.
 */
+ (void)fetchMessageUnreadCountInBackground;

/**
 *  Returns the CarnivalMessageStream ViewController wrapped in a UINavigationController.
 *
 *  @warning The CarnivalMessageStream single object holds a strong reference to this navigation controller.
 *
 *  @return A UINavigationController with the CarnivalMessageStream as it's rootViewController.
 */

+ (UINavigationController *)streamNavigationController;

/**
 *  Sets the delegate for the CarnivalMessageStream.
 *
 *  @param delegate the object you wish to be the delegate of the CarnivalMessageStream.
 */

+ (void)setDelegate:(id<CarnivalMessageStreamDelegate>)delegate;

@end
