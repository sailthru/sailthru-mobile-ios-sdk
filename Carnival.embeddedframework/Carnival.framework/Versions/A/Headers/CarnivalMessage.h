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
 * createdAt - The time at which the message was created.
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 * messageID - The unique ID of the message.
 */
@property (nonatomic, strong) NSString *messageID;

/**
 * text - The body text of the message.
 */
@property (nonatomic, strong) NSString *text;

/**
 * title - The title of the message.
 */
@property (nonatomic, strong) NSString *title;

/**
 * type - The type of the message.
 */
@property (nonatomic, assign) CarnivalMessageType type;

/**
 * imageURL - The URL of the image attached to the message. Nil if no image attached.
 */
@property (nonatomic, strong) NSURL *imageURL;

/**
 * URL - The URL attached to the message. Nil if no URL attached.
 */
@property (nonatomic, strong) NSURL *URL;


/**
 * videoURL - The URL of the video attached to the message. Nil if no video attached.
 */
@property (nonatomic, strong) NSURL *videoURL;

@end
