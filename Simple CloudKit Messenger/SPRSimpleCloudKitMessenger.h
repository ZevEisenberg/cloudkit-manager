//
//  SPRSimpleCloudKitMessenger.h
//  CloudKit Manager
//
//  Created by Bob Spryn on 6/11/14.
//  Copyright (c) 2014 Sprynthesis. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;
@import CloudKit;

typedef NS_ENUM(NSUInteger, SPRSimpleCloudMessengerError) {
    SPRSimpleCloudMessengerErrorUnexpected,
    SPRSimpleCloudMessengerErroriCloudAccount,
    SPRSimpleCloudMessengerErrorMissingDiscoveryPermissions,
    SPRSimpleCloudMessengerErrorNetwork,
    SPRSimpleCloudMessengerErrorServiceUnavailable,
    SPRSimpleCloudMessengerErrorCancelled,
};

extern NSString *const SPRSimpleCloudKitMessengerErrorDomain;

@interface SPRSimpleCloudKitMessenger : NSObject

+ (SPRSimpleCloudKitMessenger *) sharedMessenger;
- (void) verifyiCloudAccountStatusWithCompletionHandler:(void (^)(NSError *error)) completionHandler;
- (void) promptToBeDiscoverableIfNeededWithCompletionHandler:(void (^)(NSError *error)) completionHandler;
- (void) discoverAllFriendsWithCompletionHandler:(void (^)(NSArray *friendRecords, NSError *error)) completionHandler;
- (void) subscribeWithCompletionHandler:(void (^)(NSError *error)) completionHandler;
- (void) sendMessage:(NSString *)message withImageURL:(NSURL *)imageURL toUserRecordID:(CKRecordID*)userRecordID withCompletionHandler:(void (^)(NSError *error)) completionHandler;
- (void) fetchActiveUserInfoWithCompletionHandler:(void (^)(CKDiscoveredUserInfo * userInfo, NSError *error)) completionHandler;
@end