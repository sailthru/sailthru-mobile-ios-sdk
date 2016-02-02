//
//  CarnivalStreamViewController.h
//  Carnival
//
//  Created by Carnival Mobile
//  Copyright (c) 2015 Carnival Mobile. All rights reserved.
//
//  For documentation see http://docs.carnival.io
//

#import <UIKit/UIKit.h>

#define DEPRECATION_MESSAGE "CarnivalStreamViewController has been deprecated in favour for custom streams that suit the look and feel of your app, enhancing the user experience. http://docs.carnival.io/docs/setting-up-in-app-messaging#section-integrating-the-message-stream"

__attribute__((deprecated(DEPRECATION_MESSAGE)))

@interface CarnivalStreamViewController : UIViewController

@end
