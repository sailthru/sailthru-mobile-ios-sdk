//
//  ViewController.m
//  ExampleProject
//
//  Created by Blair McArthur on 19/12/13.
//  Copyright (c) 2013 Carnival Labs. All rights reserved.
//

#import "ExampleViewController.h"
#import <Carnival/Carnival.h>
#import "UIBarButtonItem+CPBarButtonItems.h"

@interface ExampleViewController () <CarnivalMessageStreamDelegate, UINavigationControllerDelegate>

@end

@implementation ExampleViewController

#pragma mark - view lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Set this viewcontroller as the CarnivalMessageStream's delegate
    
    [CarnivalMessageStream setDelegate:self];
    
    // Style the stream naivgation controller to have a blue navigation bar and white text
    
    UINavigationController *navVC = [CarnivalMessageStream streamNavigationController];
    [navVC setDelegate:self];
    [navVC.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName : [UIColor whiteColor]}];
    
    if (floor(NSFoundationVersionNumber) <= NSFoundationVersionNumber_iOS_6_1)
    {
        [navVC.navigationBar setTintColor:[UIColor blueColor]];
    }
    else
    {
        [navVC.navigationBar setBarTintColor:[UIColor blueColor]];
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleDefault];
}

#pragma mark - CarnivalMessageStreamDelegate

- (void)carnivalMessageStreamNeedsDisplay:(UINavigationController *)streamNavigationController fromApplicationState:(UIApplicationState)applicationState
{
    if (!self.presentedViewController)
    {
        // When the application is active we want to animate the Carnival Message Stream onto the screen
        // Otherwise the application is in the background or inactive so we want to have the Carnival Message Stream there when the application is active
        
        BOOL animated = applicationState == UIApplicationStateActive ? YES : NO;
        
        [self presentViewController:streamNavigationController animated:animated completion:NULL];
    }
}

- (void)willShowMessageStream:(UIViewController *)messageStreamViewController
{
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
}

- (void)willShowMessageDetail:(UIViewController *)messageDetailViewController
{
    // Note: this will only work on iOS 7+
    
    [messageDetailViewController.navigationItem.leftBarButtonItem setTintColor:[UIColor whiteColor]];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
}

#pragma mark - UINavigationControllerDelegate

- (void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated
{
    // Insert a close button as the right bar button item of all navigation items
    
    viewController.navigationItem.rightBarButtonItem = [UIBarButtonItem cp_closeButtonWithTarget:self action:@selector(closeButtonPressed:)];
}

#pragma mark - pressed actions

- (void)closeButtonPressed:(UIButton *)button
{
    [self dismissViewControllerAnimated:YES completion:NULL];
}

- (IBAction)getTagsButtonPressed:(UIButton *)sender
{
    // Asyncronously gets the tags for this device.
    
    [Carnival getTagsInBackgroundWithResponse:^(NSArray *tags, NSError *error) {
       
        NSLog(@"getTagsInBackgroundWithResponse returned tags: %@",tags);
        
    }];
}

- (IBAction)addTagButtonPressed:(UIButton *)sender
{
    // Asyncronously adds the tag for this device
    // If the tag is already registered with Carnival, this method does not add the tag again.
    
    [Carnival addTags:@[@"CARNIVAL_ADD_TAG_EXAMPLE_TAG"] inBackgroundWithResponse:^(NSArray *tags, NSError *error) {
       
        NSLog(@"addTag:inBackgroundWithResponse: returned tags: %@",tags);
        
    }];
}

- (IBAction)setTagsButtonPressed:(UIButton *)sender
{
    NSArray *exampleTags = @[
                             @"CARNIVAL_SET_TAGS_EXAMPLE_TAG_1",
                             @"CARNIVAL_SET_TAGS_EXAMPLE_TAG_2"
                            ];
    
    // Asyncronously sets the tags for Carnival for this device
    // Calling this method will overwrite any previously set tags for this device.
    // Passing nil for the tags argument will clear the tags for this device
    
    [Carnival setTagsInBackground:exampleTags withResponse:^(NSArray *tags, NSError *error) {
       
        NSLog(@"setTagsInBackground:withResponse: returned tags: %@",tags);
        
    }];
}

- (IBAction)showMessageStreamButtonPressed:(UIButton *)sender
{
    // Retrieve the streamNavigationController and present it like you would any normal UIViewController
    
    UINavigationController *navVC = [CarnivalMessageStream streamNavigationController];
    
    [self presentViewController:navVC animated:YES completion:NULL];
}

@end
