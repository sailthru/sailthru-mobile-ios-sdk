//
//  CloseBarButtonItem.m
//  CustomPresentationExamples
//
//  Created by Blair McArthur on 16/04/15.
//
//

#import "CloseBarButtonItem.h"

@implementation CloseBarButtonItem

#pragma mark - init

+ (instancetype)whiteCloseButtonForTarget:(id)target action:(SEL)action {
    UIButton *closeButton = [[UIButton alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 44.0f, 44.0f)];
    
    [closeButton setImageEdgeInsets:UIEdgeInsetsMake(11.0f, 30.0f, 11.0f, -8.0f)];
    [closeButton setImage:[self whiteCloseButtonImage] forState:UIControlStateNormal];
    [closeButton addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    
    CloseBarButtonItem *closeItem = [[CloseBarButtonItem alloc] initWithCustomView:closeButton];
    [closeItem setTintColor:[UIColor whiteColor]];
    
    return closeItem;
}

#pragma mark - overriden getters/setters

- (void)setTintColor:(UIColor *)tintColor {
    [super setTintColor:tintColor];
    
    [self.customView setTintColor:tintColor];
}

#pragma mark - images

+ (UIImage *)whiteCloseButtonImage {
    return [[UIImage imageNamed:@"close_button.png"] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}

@end
