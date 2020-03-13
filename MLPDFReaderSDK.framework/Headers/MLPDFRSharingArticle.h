//
//  MLPDFRSharingArticle.h
//  MLPDFReader
//
//  Created by Maxime Le Moine on 18/08/2017.
//  Copyright © 2017 miLibris. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLPDFRSharingArticle : NSObject

/**
 The unique identifier of the article
 */
@property (nonatomic, strong, readonly, nonnull) NSString *mid;

/**
 The file URL where the article content is located
 */
@property (nonatomic, strong, readonly, nonnull) NSURL *url;

/**
 The title of the article
 */
@property (nonatomic, strong, readonly, nullable) NSString *title;

/**
 The title of the edition containing the article
 */
@property (nonatomic, strong, readonly, nullable) NSString *editionTitle;

/**
 The subtitle of the edition containing the article
 */
@property (nonatomic, strong, readonly, nullable) NSString *editionSubtitle;

/**
 Load the content located at URL and return the raw HTML
 */
- (nullable NSString *)htmlContent;

@end
