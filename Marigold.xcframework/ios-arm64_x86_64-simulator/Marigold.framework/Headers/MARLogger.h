//
//  MARLogger.h
//  Sailthru Mobile
//
//  Created by Sailthru Mobile.
//  Copyright © 2019 Sailthru. All rights reserved.
//

typedef NS_ENUM(NSInteger, MARLogLevel) {
    MARLogLevelDefault,
    MARLogLevelInfo,
    MARLogLevelDebug,
    MARLogLevelError,
    MARLogLevelFault
};

@protocol MARLogger <NSObject>

- (void)logWithLevel:(MARLogLevel)level message:(NSString *)message;

@end
