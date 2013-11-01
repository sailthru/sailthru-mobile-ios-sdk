//
//  CPMessage.h
//  Carnival
//
//  Copyright (c) 2012 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPMessage : NSObject

@property (nonatomic, strong, readonly) NSString *messageID;
@property (nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) NSURL *imageURL;
@property (nonatomic, strong, readonly) NSURL *contentURL;
@property (nonatomic, strong, readonly) NSDate *createdAt;

- (id)initWithMessageID:(NSString *)messageID;

@end
