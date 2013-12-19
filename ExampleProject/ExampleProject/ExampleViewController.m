//
//  ViewController.m
//  ExampleProject
//
//  Created by Blair McArthur on 19/12/13.
//  Copyright (c) 2013 Carnival Labs. All rights reserved.
//

#import "ExampleViewController.h"
#import <Carnival/Carnival.h>

@implementation ExampleViewController

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
    
    [Carnival addTag:@"CARNIVAL_ADD_TAG_EXAMPLE_TAG" inBackgroundWithResponse:^(NSArray *tags, NSError *error) {
       
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
    // Shows the message stream using the specified duration and completion handler
    
    [CarnivalMessageStream showMessageStreamWithDuration:0.4f completion:^(BOOL finished) {
       
        NSLog(@"Carnival Message Stream was shown");
        
    }];
}

@end
