//
//  STMLogger.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

typedef NS_ENUM(NSInteger, STMLogLevel) {
    STMLogLevelDefault,
    STMLogLevelInfo,
    STMLogLevelDebug,
    STMLogLevelError,
    STMLogLevelFault
};

@protocol STMLogger <NSObject>

- (void)logWithLevel:(STMLogLevel)level message:(NSString *)message;

@end
