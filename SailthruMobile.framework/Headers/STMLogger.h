//
//  STMLogger.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

#import "CarnivalLogger.h"

typedef NS_ENUM(NSInteger, STMLogLevel) {
    STMLogLevelDefault,
    STMLogLevelInfo,
    STMLogLevelDebug,
    STMLogLevelError,
    STMLogLevelFault
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@protocol STMLogger <CarnivalLogger>
#pragma clang diagnostic pop

- (void)logWithLevel:(STMLogLevel)level message:(NSString *)message;

@end
