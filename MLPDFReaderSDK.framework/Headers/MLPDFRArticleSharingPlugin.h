//
//  MLPDFRArticleSharingPlugin.h
//  MLPDFReader
//
//  Created by Jeremy FAIVRE on 12/11/2014.
//  Copyright (c) 2014 miLibris. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MLPDFRSharingArticle.h"

/**
 The protocol that must be implemented by article sharing plugins.
 
 When the user taps on the share button when viewing an article, the available plugins will be displayed in an alert controller.
 */
@protocol MLPDFRArticleSharingPlugin <NSObject>

/**
 The name that will be displayed in the sharing alert controller
 */
@property (nonnull, readonly) NSString *actionName;

/**
 Sent when the user taps the plugin button from the sharing alert controller
 @param article An object containing the article properties
 @param viewController The view controller that is presenting the article
 @param barButtonItem The share button
 */
- (void)shareArticle:(nonnull MLPDFRSharingArticle *)article
  fromViewController:(nonnull UIViewController *)viewController
       barButtonItem:(nonnull UIBarButtonItem *)barButtonItem;

@end
