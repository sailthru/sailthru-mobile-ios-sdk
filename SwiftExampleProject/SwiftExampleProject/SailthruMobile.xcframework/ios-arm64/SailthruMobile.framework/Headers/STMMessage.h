//
//  STMMessage.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Declares which type the STMMessage is. Types are defined at time of authoring.
 **/
typedef NS_ENUM(NSInteger, STMMessageType) {
    STMMessageTypeText,
    STMMessageTypeImage,
    STMMessageTypeLink,
    STMMessageTypeVideo,
    STMMessageTypeStandardPush,
    STMMessageTypeOther
};

@interface STMMessage : NSObject

/**
 * The time at which the message was created.
 */
@property (nonatomic, strong, nonnull) NSDate *createdAt;

/**
 * The unique ID of the message.
 */
@property (nonatomic, strong, nonnull) NSString *messageID;

/**
 * The body text of the message.
 */
@property (nonatomic, strong, nullable) NSString *text;

/**
 * The body text of the message rendered into HTML.
 */
@property (nonatomic, strong, nullable) NSString *htmlText;

/**
 * The title of the message.
 */
@property (nonatomic, strong, nonnull) NSString *title;

/**
 * The type of the message.
 */
@property (nonatomic, assign) STMMessageType type;

/**
 * The URL of the image attached to the message. Nil if no image attached.
 */
@property (nonatomic, strong, nullable) NSURL *imageURL;

/**
 * The URL attached to the message. Nil if no URL attached.
 */
@property (nonatomic, strong, nullable) NSURL *URL;

/**
 * The URL of the video attached to the message. Nil if no video attached.
 */
@property (nonatomic, strong, nullable) NSURL *videoURL;

/**
 * Whether or not the message has been marked as read.
 */
@property (nonatomic, assign, readonly, getter=isRead) BOOL read;

/**
 * A dictionary of arbitary attributes set on the message.
 */
@property (nonatomic, strong, nullable) NSDictionary *attributes;

/**
 * Whether or not a message had a push attached.
 */
@property (nonatomic, assign, readonly, getter=hasPushAttached) BOOL pushAttached;

@end

NS_ASSUME_NONNULL_END
