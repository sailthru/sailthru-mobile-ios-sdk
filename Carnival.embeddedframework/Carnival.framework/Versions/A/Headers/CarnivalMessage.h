//
//  CarnivalMessage.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnivalmobile.com
//

#import <Foundation/Foundation.h>
#import "CarnivalMacros.h"

/**
 * Declares which type the Carnival Message is. Types are defined at time of authoring.
 **/
typedef NS_ENUM(NSInteger, CarnivalMessageType) {
    CarnivalMessageTypeText,
    CarnivalMessageTypeImage,
    CarnivalMessageTypeLink,
    CarnivalMessageTypeVideo,
    CarnivalMessageTypeFakeCall,
    CarnivalMessageTypeStandardPush,
    CarnivalMessageTypeOther
};

@interface CarnivalMessage : NSObject

/**
 * The time at which the message was created.
 */
@property (nonatomic, strong, carnival_nonnull) NSDate *createdAt;

/**
 * The unique ID of the message.
 */
@property (nonatomic, strong, carnival_nonnull) NSString *messageID;

/**
 * The body text of the message.
 */
@property (nonatomic, strong, carnival_nullable) NSString *text;

/**
 * The title of the message.
 */
@property (nonatomic, strong, carnival_nonnull) NSString *title;

/**
 * The type of the message.
 */
@property (nonatomic, assign) CarnivalMessageType type;

/**
 * The URL of the image attached to the message. Nil if no image attached.
 */
@property (nonatomic, strong, carnival_nullable) NSURL *imageURL;

/**
 * The URL attached to the message. Nil if no URL attached.
 */
@property (nonatomic, strong, carnival_nullable) NSURL *URL;

/**
 * The URL of the video attached to the message. Nil if no video attached.
 */
@property (nonatomic, strong, carnival_nullable) NSURL *videoURL;

/**
 * Whether or not the message has been marked as read.
 */
@property (nonatomic, assign, readonly, getter=isRead) BOOL read;

@end
