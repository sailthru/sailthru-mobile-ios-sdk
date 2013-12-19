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

@interface CarnivalMessageStream : NSObject

/**
 *  Shows the message stream using the specified duration and completion handler
 *
 *  @param duration The total duration of the animations, measured in seconds. If you specify a negative value or 0, the changes are made without animating them.
 *  @param completion A block object to be executed when the animation sequence ends. This block has no return value and takes a single Boolean argument that indicates whether or not the animations actually finished before the completion handler was called. If the duration of the animation is 0, this block is performed at the beginning of the next run loop cycle. This parameter may be NULL.
 *
 *  Note: On iOS versions below 5, this method does nothing.
 */

+ (void)showMessageStreamWithDuration:(CGFloat)duration completion:(void (^)(BOOL finished))completion;

/**
 *  Dismisses the message stream using the specified duration and completion handler
 *
 *  @param duration The total duration of the animations, measured in seconds. If you specify a negative value or 0, the changes are made without animating them.
 *  @param completion A block object to be executed when the animation sequence ends. This block has no return value and takes a single Boolean argument that indicates whether or not the animations actually finished before the completion handler was called. If the duration of the animation is 0, this block is performed at the beginning of the next run loop cycle. This parameter may be NULL.
 *
 *  Note: On iOS versions below 5, this method does nothing.
 */

+ (void)dismissMessageStreamWithDuration:(CGFloat)duration completion:(void (^)(BOOL finished))completion;

@end
