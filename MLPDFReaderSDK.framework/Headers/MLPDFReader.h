//
//  MLPDFReader.h
//  MLPDFReader
//
//  Created by Jeremy FAIVRE on 21/10/2014.
//  Copyright (c) 2014 miLibris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MLPDFReaderBaseConfiguration.h"
#import "MLPDFRReaderViewController.h"

@class MLPDFReader;
@class MLProductInfo;

#pragma mark - PDF Reader Delegate

@protocol MLPDFReaderDelegate <NSObject>

/**
 Called when the pdf reader should be closed.
 It is the responsibility of the called to close the related view controller.
 */
- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didFinishReading:(nonnull MLPDFRReaderViewController *)readerViewController;

@optional

/**
 Called when the pdf reader controller is about to rotate.
 You should return the same value that "- (NSUInteger)supportedInterfaceOrientations" for the given view controller; By default, this allows all interface orientations
 */
- (UIInterfaceOrientationMask)pdfReader:(nonnull MLPDFReader *)pdfReader supportedInterfaceOrientationsForController:(nonnull MLPDFRReaderViewController *)readerViewController;

// Stats

/**
 Page number starts from ONE (not zero).
 */
- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didMoveToPageNumber:(NSInteger)pageNumber;

/**
 contentURL can be a relative path
 */
- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didOpenLinkBoxWithContentURL:(nonnull NSString *)contentURL;

- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didOpenSlideshowBoxWithResourceName:(nonnull NSString *)resourceName;

/**
 contentURL can be a relative path
 */
- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didOpenVideoBoxWithContentURL:(nonnull NSString *)contentURL;

- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didOpenHtml5BoxWithResourceName:(nonnull NSString *)resourceName;

- (void)pdfReaderDidOpenNavigationDrawer:(nonnull MLPDFReader *)pdfReader;
- (void)pdfReaderDidCloseNavigationDrawer:(nonnull MLPDFReader *)pdfReader;

- (void)pdfReaderDidOpenArticleMode:(nonnull MLPDFReader *)pdfReader;
- (void)pdfReaderDidCloseArticleMode:(nonnull MLPDFReader *)pdfReader;

/**
 Dictionary contains article info
 */
- (void)pdfReader:(nonnull MLPDFReader *)pdfReader didOpenArticle:(nonnull MLPDFRSharingArticle *)article;

@end


@interface MLPDFReader : NSObject

#pragma mark - Delegate

@property (nullable, nonatomic, weak) id<MLPDFReaderDelegate> delegate;

#pragma mark - Properties

@property (nonnull, nonatomic, strong) MLProductInfo *productInfo;

@property (nonnull, nonatomic, strong) MLPDFReaderBaseConfiguration *config;

@property (nonnull, nonatomic, strong) NSArray<id <MLPDFRArticleSharingPlugin>> *articleSharingPlugins;

#pragma mark - Initializer

/**
 Initialize pdf reader with the given content URL and delegate
 */
- (nullable instancetype)initWithContentURL:(nonnull NSURL *)contentURL
                                     config:(nullable MLPDFReaderBaseConfiguration *)config
                                   delegate:(nullable id<MLPDFReaderDelegate>)delegate
                                      error:(NSError *  __nullable * __nullable)errorRef;

/**
 Initialize pdf reader with the given product info and delegate
 */
- (nullable instancetype)initWithProductInfo:(nonnull MLProductInfo *)productInfo
                                      config:(nullable MLPDFReaderBaseConfiguration *)config
                                    delegate:(nullable id<MLPDFReaderDelegate>)delegate
                                       error:(NSError *  __nullable * __nullable)errorRef;

#pragma mark - Close

- (void)close;

#pragma mark - Encryption

/// @name Configuring the cryptography system

/// Set the cryprographic application ID.
///
/// This is required for reading content protected by the miLibris DRM.
///
/// @param appID An hexstring token provided by miLibris.
+ (void)setApplicationID:(nullable NSString *)appID;
+ (nullable NSString *)applicationID;

/// Set the cryprographic user ID.
///
/// This is required for reading content protected by the miLibris DRM.
///
/// @param userID An hexstring token unique to the user.
/// @see MLFoundationUserIDFromString
+ (void)setUserID:(nullable NSString *)userID;
+ (nullable NSString *)userID;

+ (nonnull instancetype) new NS_UNAVAILABLE;
- (nonnull instancetype)init NS_UNAVAILABLE;

@end
