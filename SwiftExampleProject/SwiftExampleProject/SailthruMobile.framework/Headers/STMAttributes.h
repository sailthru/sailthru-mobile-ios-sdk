//
//  STMAttributes.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "CarnivalAttributes.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, STMAttributesMergeRule) {
    STMAttributesMergeRuleUpdate,
    STMAttributesMergeRuleReplace
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface STMAttributes : CarnivalAttributes
#pragma clang diagnostic pop

@end

NS_ASSUME_NONNULL_END
