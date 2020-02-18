//
//  STMMessage.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "CarnivalMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Declares which type the Carnival Message is. Types are defined at time of authoring.
 **/
typedef NS_ENUM(NSInteger, STMMessageType) {
    STMMessageTypeText,
    STMMessageTypeImage,
    STMMessageTypeLink,
    STMMessageTypeVideo,
    STMMessageTypeStandardPush,
    STMMessageTypeOther
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface STMMessage : CarnivalMessage
#pragma clang diagnostic pop

@end

NS_ASSUME_NONNULL_END
