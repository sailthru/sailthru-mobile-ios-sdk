//
//  CPMessageList.h
//  Carnival
//
//  Copyright (c) 2012 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPMessageList : NSObject

+ (CPMessageList *)sharedInstance;
- (void)messages:(void (^) (NSArray *messages, BOOL hasMoreMessages, NSError *error))handler;
- (void)newMessageCount:(void (^) (NSInteger newMessageCount, NSError *error))handler;
- (void)setViewedMessages:(NSArray *)messages;

@end
