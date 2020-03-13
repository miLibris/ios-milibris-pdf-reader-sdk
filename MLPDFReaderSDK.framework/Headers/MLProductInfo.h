//
//  MLProductInfo.h
//  MLFoundation
//
//  Created by Maxime Le Moine on 15/10/2019.
//  Copyright © 2019 miLibris. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
Represents a product packaged in a miLibris ".complete" archive
*/
@interface MLProductInfo : NSObject

/**
The local URL of the product's file or directory.
*/
@property (nonatomic, strong, nonnull, readonly) NSURL *url;

/**
true if the product files are encrypted, false otherwise.
*/
@property (nonatomic, readonly) BOOL isEncrypted;

/**
The URL to the product's decryption key.
This value won't be used if isEncrypted is false.

If the key is self-contained in the product, this value already contains the path to the internal key.
Otherwise, the key must be retrieved separatly. In this case, set the path to the key manually.
*/
@property (nonatomic, strong, nullable) NSURL *keyURL;

- (nonnull instancetype)initWithURL:(nonnull NSURL *)url isEncrypted:(BOOL)isEncrypted;

#pragma mark - Deprecated

@property (nonatomic, nonnull, readonly) NSString *path
__deprecated_msg("use url instead");

@property (nonatomic, nonnull, readonly) NSString *blobPath
__deprecated_msg("use keyURL instead");

@end
