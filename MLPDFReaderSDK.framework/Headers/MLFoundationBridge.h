//
//  MLFoundationBridge.h
//  MLFoundation
//
//  Created by Maxime Le Moine on 15/10/2019.
//  Copyright © 2019 miLibris. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MLProductInfo;

@interface MLFoundationBridge : NSObject

+ (nullable NSArray<MLProductInfo *> *)productsInRelease:(nonnull NSString *)releasePath
                                                   error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef
__deprecated_msg("use MLRelease(url:).products:error: instead");

+ (BOOL)unpackArchive:(nonnull NSString *)archivePath
          toDirectory:(nonnull NSString *)extractionPath
                error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef
__deprecated_msg("use MLArchive.extract:inDirectory:error: instead");

+ (void)setUpDriverPurgeOnMemoryWarning
__deprecated_msg("use MLSecureDataProvider.purgeOnMemoryWarnings instead");

@end
