//
//  MLPDFRReaderViewController.h
//  MLPDFReader
//
//  Created by Jeremy FAIVRE on 23/10/2014.
//  Copyright (c) 2014 miLibris. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MLPDFReader;

@interface MLPDFRReaderViewController: UIViewController

/**
 The associated MLPDFReader instance
 */
@property (nonatomic, nonnull, strong) MLPDFReader *pdfReader;

/**
 Create a root view controller based on the given MLPDFReader instance, initial page and/or initial article
 */
- (nonnull instancetype)initWithPDFReader:(nonnull MLPDFReader *)pdfReader;

/**
 Create a root view controller based on the given MLPDFReader instance, initial page and/or initial article
 */
- (nonnull instancetype)initWithPDFReader:(nonnull MLPDFReader *)pdfReader
                         initialPageIndex:(NSInteger)initialPageIndex;

/**
 Create a root view controller based on the given MLPDFReader instance, initial page and/or initial article
 */
- (nonnull instancetype)initWithPDFReader:(nonnull MLPDFReader *)pdfReader
                        initialArticleMID:(nullable NSString *)initialArticleMID;

/**
 Create a root view controller based on the given MLPDFReader instance, initial page and/or initial article
 */
- (nonnull instancetype)initWithPDFReader:(nonnull MLPDFReader *)pdfReader
                         initialPageIndex:(NSInteger)initialPageIndex
                        initialArticleMID:(nullable NSString *)initialArticleMID;

+ (nonnull instancetype) new NS_UNAVAILABLE;
- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(nonnull NSCoder *)aDecoder NS_UNAVAILABLE;

@end
