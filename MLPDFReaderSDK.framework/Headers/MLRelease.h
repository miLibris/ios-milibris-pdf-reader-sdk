//
//  MLRelease.h
//  MLFoundation
//
//  Created by Maxime Le Moine on 15/10/2019.
//  Copyright © 2019 miLibris. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MLProductInfo.h"

/**
An unpacked complete container.

This directory contains a manifest.xml and a directory for each contained product.
*/
@interface MLRelease : NSObject

@property (nonatomic, strong, nonnull, readonly) NSURL *url;

/**
 An array of `MLProductInfo`. A release usually contains a single product.
*/
@property (nonatomic, strong, nonnull, readonly) NSArray<MLProductInfo *> *products;

- (nonnull instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithURL:(nonnull NSURL *)url
                               error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef;

/**
Retrieve information about the single product contained in the release.

Throws an error if there is not exactly one product in the release
*/
- (nullable MLProductInfo *)uniqueProductWithError:(NSError *__autoreleasing _Nullable * _Nullable)errorRef;

@end

#define MLReleaseErrorDomain @"MLRelease"

typedef NS_ENUM(NSUInteger, MLReleaseErrorCode) {
    MLReleaseErrorCodeManifestNotFound = 1,
    MLReleaseErrorCodeProductHrefNotFound = 2,
    MLReleaseErrorCodeXMLParserFailed = 3,
    MLReleaseErrorCodeNonUniqueProduct = 4,
};
