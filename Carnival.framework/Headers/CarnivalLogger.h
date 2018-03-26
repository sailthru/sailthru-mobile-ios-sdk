//
//  CarnivalLogger.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2017 Carnival.io. All rights reserved.
//

typedef NS_ENUM(NSInteger, CarnivalLogLevel) {
    CarnivalLogLevelDefault,
    CarnivalLogLevelInfo,
    CarnivalLogLevelDebug,
    CarnivalLogLevelError,
    CarnivalLogLevelFault
};

@protocol CarnivalLogger  <NSObject>

- (void)logWithLevel:(CarnivalLogLevel)level message:(NSString *)message;

@end
