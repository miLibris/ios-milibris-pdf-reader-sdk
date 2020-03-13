//
//  MLArchive.h
//  MLFoundation
//
//  Created by Maxime Le Moine on 10/10/2019.
//  Copyright © 2019 miLibris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLArchive : NSObject

- (nonnull instancetype)init NS_UNAVAILABLE;

+ (BOOL)extract:(nonnull NSURL *)archiveURL
    inDirectory:(nonnull NSURL *)extractionURL
          error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef;

+ (BOOL)createZipAt:(nonnull NSURL *)archiveURL
        sourceFiles:(nonnull NSArray<NSURL *> *)sourceFiles
              error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef;

+ (BOOL)createTarGzAt:(nonnull NSURL *)archiveURL
          sourceFiles:(nonnull NSArray<NSURL *> *)sourceFiles
                error:(NSError *__autoreleasing _Nullable * _Nullable)errorRef;

@end

#define LibArchiveErrorDomain @"LibArchive"
#define StatErrorDomain @"Stat"
#define MLArchiveErrorDomain @"MLArchive"

typedef NS_ENUM(NSUInteger, MLArchiveErrorCode) {
    MLArchiveErrorCodeArchiveNotFound = 1,
    MLArchiveErrorCodeArchiveNotAFile = 2,
    MLArchiveErrorCodeExtractionPAthNotADirectory = 3,
    MLArchiveErrorCodeExtractionDirectoryNotEmpty = 4,
    MLArchiveErrorCodeArchiveAlreadyExists = 5,
    MLArchiveErrorCodeDuplicateSourceFilename = 6,
};
