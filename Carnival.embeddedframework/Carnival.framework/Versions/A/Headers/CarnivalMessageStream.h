//
//  CarnivalStream.h
//  Carnival
//
//  Created by Kup on 18/11/13.
//  Copyright (c) 2013 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString * const CarnivalMessageStreamWillShowStreamNotification;
extern NSString * const CarnivalMessageStreamDidShowStreamNotification;
extern NSString * const CarnivalMessageStreamWillDismissStreamNotification;
extern NSString * const CarnivalMessageStreamDidDismissStreamNotification;

extern NSString * const CarnivalMessageStreamUnreadMessageCountDidChangeNotification;

@interface CarnivalMessageStream : NSObject

/** @name Showing/dismissing the Carnival Message Stream */

/**
 *  Shows the message stream using the specified duration and completion handler
 *
 *  @param duration The total duration of the animations, measured in seconds. If you specify a negative value or 0, the changes are made without animating them.
 *  @param completion A block object to be executed when the animation sequence ends. This block has no return value and takes a single Boolean argument that indicates whether or not the animations actually finished before the completion handler was called. If the duration of the animation is 0, this block is performed at the beginning of the next run loop cycle. This parameter may be NULL.
 *
 *  @warning On iOS versions below 5, this method does nothing.
 */

+ (void)showMessageStreamWithDuration:(CGFloat)duration completion:(void (^)(BOOL finished))completion;

/**
 *  Dismisses the message stream using the specified duration and completion handler
 *
 *  @param duration The total duration of the animations, measured in seconds. If you specify a negative value or 0, the changes are made without animating them.
 *  @param completion A block object to be executed when the animation sequence ends. This block has no return value and takes a single Boolean argument that indicates whether or not the animations actually finished before the completion handler was called. If the duration of the animation is 0, this block is performed at the beginning of the next run loop cycle. This parameter may be NULL.
 *
 *  @warning On iOS versions below 5, this method does nothing.
 */

+ (void)dismissMessageStreamWithDuration:(CGFloat)duration completion:(void (^)(BOOL finished))completion;

/** @name Message statistics */

/**
 *  Asynchronously returns the total number of messages in the message stream
 *
 *  @deprecated use the messagesCounts: method instead  
 *
 *  @param handler A block object which returns either the total number of messages in the message stream when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *  @warning This method does nothing if the handler block is NULL
 *
 *  @warning On iOS versions below 5, this method does nothing.
 */

+ (void)messagesCount:(void (^)(NSUInteger count, NSError *error))handler __attribute((deprecated("use the messagesCounts: method instead")));

/**
 *  Asynchronously returns the total number of messages and the number of unread messages in the message stream
 *
 *  Note: If you are wanting to be notified when the unread messages count updates, observe the CarnivalMessageStreamUnreadMessageCountDidChangeNotification notification
 *
 *  @param handler A block object which returns either the total number of messages in the message stream and the number of unread messages when there is no error.  The error will be non-nil if there was a problem retrieving the message count.
 *
 *
 *  @warning This method does nothing if the handler block is NULL
 *
 *  @warning On iOS versions below 5, this method does nothing.
 */

+ (void)messagesCounts:(void (^)(NSUInteger totalMessagesCount, NSUInteger unreadMessagesCount, NSError *error))handler;

@end
