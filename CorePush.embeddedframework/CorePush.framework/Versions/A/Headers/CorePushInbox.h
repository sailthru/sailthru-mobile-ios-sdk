//
//  CorePushInbox.h
//  CorePush
//
//  Created by Cody Bunea on 10/12/12.
//  Copyright (c) 2012 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CPMessage.h"
#import "CPMessageList.h"

@interface CorePushInbox : NSObject

typedef enum {
    CPSupportedInterfaceOrientationsAll,
    CPSupportedInterfaceOrientationsPortrait,
    CPSupportedInterfaceOrientationsLandscape,
} CPSupportedInterfaceOrientations;


/** Core Push Inbox Methods **/

/**
 Sets the ViewController that will present the Core Push Inbox.
 
 @param presentingViewController The UIViewController that will present the Core Push Inbox
 
 */
+ (void)setPresentingViewController:(UIViewController *)presentingViewController;

/**
 Presents the Core Push inbox modally, using the View Controller stored via +[CorePush setPresentingViewController], and uses the rootViewController if not set
 
 @param animated Passing YES will animate the presentation of the Core Push Inbox
 
 */
+ (void)presentInboxAnimated:(BOOL)animated;

/**
 Presents the Core Push inbox modally, using the View Controller passed in to present it.
 Returns the navigation controller used, so that any styling can be applied.
 
 @param presentingViewController The UIViewController to present the Core Push Inbox
 @param animated Passing YES will animate the presentation of the Core Push Inbox 
 
 */
+ (void)presentInboxFromController:(UIViewController *)presentingViewController animated:(BOOL)animated;


/**
 Returns a count of new messages in the Core Push Inbox since the user last viewed the inbox
 
 @param handler
 
        a handler block that that returns
        
        newMessagesCount The Number of new messages
        error An Error object returned if the request for the new messages count failed in some way
 
 */
+ (void)newMessageCount:(void (^) (NSInteger newMessageCount, NSError *error))handler;

/**
 Sets the logo image on the navigation bar in the Core Push Inbox.
 
 @param logoImage The new logo image for the navigation bar in the Core Push Inbox
 
 */
+ (void)setInboxLogo:(UIImage *)logoImage;

/**
 Sets the supported orientations of the Core Push Inbox.  This supports all by default.
 
 @param orientation The supported interface orientations for the Core Push inbox, default is CPSupportedInterfaceOrientationsAll
 
 typedef enum {
    CPSupportedInterfaceOrientationsAll,
    CPSupportedInterfaceOrientationsPortrait,
    CPSupportedInterfaceOrientationsLandscape,
 } CPSupportedInterfaceOrientations;
 
 */
+ (void)setSupportedInboxOrientations:(CPSupportedInterfaceOrientations)orientations;

@end
