//
//  UIBarButtonItem+CPBarButtonItems.m
//  CustomPresentationExamples
//
//  Created by Blair McArthur on 20/08/14.
//
//

#import "UIBarButtonItem+CPBarButtonItems.h"

@implementation UIBarButtonItem (CPBarButtonItems)

+ (UIBarButtonItem *)cp_closeButtonWithTarget:(id)target action:(SEL)action
{
    UIButton *closeButton = [[UIButton alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 44.0f, 44.0f)];
    
    UIImage *closeImage = nil;
    
    if (floor(NSFoundationVersionNumber) <= NSFoundationVersionNumber_iOS_6_1)
    {
        closeImage = [UIImage imageNamed:@"close_button.png"];
        
        [closeButton setImageEdgeInsets:UIEdgeInsetsMake(11.0f, 10.0f, 11.0f, -8.0f)];
    }
    else
    {
        closeImage = [[UIImage imageNamed:@"close_button.png"] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
        
        [closeButton setImageEdgeInsets:UIEdgeInsetsMake(11.0f, 30.0f, 11.0f, -8.0f)];
    }
    
    [closeButton setImage:closeImage forState:UIControlStateNormal];
    [closeButton setTintColor:[UIColor whiteColor]];
    [closeButton addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    
    return [[UIBarButtonItem alloc] initWithCustomView:closeButton];
}

@end
