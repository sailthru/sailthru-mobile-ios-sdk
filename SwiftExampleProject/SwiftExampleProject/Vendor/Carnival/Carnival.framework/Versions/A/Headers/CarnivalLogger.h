//
//  CarnivalLogger.h
//  Carnival
//
//  Created by Carnival Mobile on 28/11/16.
//  Copyright © 2016 Carnival Mobile . All rights reserved.
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
