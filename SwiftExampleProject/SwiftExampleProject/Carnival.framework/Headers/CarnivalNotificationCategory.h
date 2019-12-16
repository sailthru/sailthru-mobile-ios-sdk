//
//  CarnivalNotificationCategory.h
//  Carnival
//
//  Created by Ian Stewart on 13/09/19.
//  Copyright © 2019 Carnival Labs . All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * Action identifers that will be returned to the app by the UNNotificationResponse actionIdentifier field when it is returned in the didReceiveNotificationResponse:withCompletionHandler method after an action is selected.
 */
extern NSString * const CarnivalNotificationActionYes;
extern NSString * const CarnivalNotificationActionNo;
extern NSString * const CarnivalNotificationActionAccept;
extern NSString * const CarnivalNotificationActionDecline;
extern NSString * const CarnivalNotificationActionLearnMore;
extern NSString * const CarnivalNotificationActionNextStep;
extern NSString * const CarnivalNotificationActionView;
extern NSString * const CarnivalNotificationActionShopNow;
extern NSString * const CarnivalNotificationActionAdd;
extern NSString * const CarnivalNotificationActionWatch;
extern NSString * const CarnivalNotificationActionSubscribe;
extern NSString * const CarnivalNotificationActionShare;
extern NSString * const CarnivalNotificationActionContinue;
