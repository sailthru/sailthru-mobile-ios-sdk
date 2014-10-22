//
//  ViewController.m
//  ExampleProject
//
//  Created by Blair McArthur on 19/12/13.
//  Copyright (c) 2013 Carnival Labs. All rights reserved.
//

#import "ExampleViewController.h"
#import <Carnival/Carnival.h>

@interface ExampleViewController () <CarnivalMessageStreamDelegate, CLLocationManagerDelegate>

@property (strong, nonatomic) CLLocationManager *locationManager;

@end

@implementation ExampleViewController

#pragma mark - view lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self setupLocationManager];
    
    // Set this viewcontroller as the CarnivalMessageStream's delegate
    
    [CarnivalMessageStream setDelegate:self];
    
    // Style the stream naivgation controller to have a blue navigation bar and white text
    
    UINavigationController *navVC = [CarnivalMessageStream streamNavigationController];
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

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [self startLocationTrackingInBackground];
}

#pragma mark - setup

- (void)setupLocationManager
{
    // Create the location manager and set ourselves as the delegate
    
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    
    // The above is all you need for significant location updates
    // For standard location services you may want some extra settings
    
    //self.locationManager.desiredAccuracy = kCLLocationAccuracyThreeKilometers
    //self.locationManager.distanceFilter = 1000.0f
}

#pragma mark - location tracking

- (void)startLocationTrackingInBackground
{
    CLAuthorizationStatus authorizationStatus = [CLLocationManager authorizationStatus];
    
    // Always check if you are authorized to start location services
    
    if (authorizationStatus != kCLAuthorizationStatusDenied && authorizationStatus != kCLAuthorizationStatusRestricted)
    {
        CLLocationManager *manager = self.locationManager;
        
        // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
        
        if ([manager respondsToSelector:@selector(requestAlwaysAuthorization)])
        {
            // Request permission to always monitor location updates, in foreground and background
            // Note: this method prompts the user for location permissions on iOS 8 and above
            
            [manager requestAlwaysAuthorization];
        }
        
        if ([CLLocationManager significantLocationChangeMonitoringAvailable])
        {
            // Note: this method prompts the user for location permissions on iOS 7 and below
            
            [manager startMonitoringSignificantLocationChanges];
        }
        else
        {
            // If you want to support devices that don't have significant location monitoring you can fall back to standard location services
            // Note: this method prompts the user for location permissions on iOS 7 and below
            
            [manager startUpdatingLocation];
        }
    }
}

- (void)stopLocationTrackingInBackground
{
    if ([CLLocationManager significantLocationChangeMonitoringAvailable])
    {
        [self.locationManager stopMonitoringSignificantLocationChanges];
    }
    else
    {
        [self.locationManager stopUpdatingLocation];
    }
}

- (void)startLocationTrackingInForegroundOnly
{
    CLAuthorizationStatus authorizationStatus = [CLLocationManager authorizationStatus];
    
    // Always check if you are authorized to start location services
    
    if (authorizationStatus != kCLAuthorizationStatusDenied && authorizationStatus != kCLAuthorizationStatusRestricted)
    {
        CLLocationManager *manager = self.locationManager;
        
        // Check if we are on iOS 8, where we have to requet permissions differently than on previous iOS versions
        
        if ([manager respondsToSelector:@selector(requestWhenInUseAuthorization)])
        {
            // Request permission to monitor location updates when the app is in use
            // Note: this method prompts the user for location permissions on iOS 8 and above
            
            [manager requestWhenInUseAuthorization];
        }
        
        // Note: this method prompts the user for location permissions on iOS 7 and below
        
        [manager startUpdatingLocation];
    }
}

- (void)stopLocationTrackingInForegroundOnly
{
    [self.locationManager stopUpdatingLocation];
}

#pragma mark - CLLocationManagerDelegate

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    // Send the last location object as that is the most recent one always
    
    [Carnival updateLocation:[locations lastObject]];
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
    
    // Note: this will only work on iOS 7+
    
    [messageStreamViewController.navigationItem.rightBarButtonItem setTintColor:[UIColor whiteColor]];
}

- (void)willShowMessageDetail:(UIViewController *)messageDetailViewController
{
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
    
    // Note: this will only work on iOS 7+
    
    [messageDetailViewController.navigationItem.leftBarButtonItem setTintColor:[UIColor whiteColor]];
    
    [messageDetailViewController.navigationItem.rightBarButtonItem setTintColor:[UIColor whiteColor]];
}

#pragma mark - pressed actions

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
