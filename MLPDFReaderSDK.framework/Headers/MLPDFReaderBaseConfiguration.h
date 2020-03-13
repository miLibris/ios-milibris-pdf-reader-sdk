//
//  MLPDFReaderBaseConfiguration.h
//  MLPDFReader
//
//  Created by Jeremy FAIVRE on 30/10/2014.
//  Copyright (c) 2014 miLibris. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MLPDFRArticleSharingPlugin.h"

@interface MLPDFReaderBaseConfiguration : NSObject

#pragma mark - Features

/**
 Enable article mode
 
 default: YES
 */
- (BOOL)allowsArticleMode;

/**
 Add an button to share or print the current PDF page
 
 default: NO
 */
- (BOOL)enablePageSharing;

/**
 Add an button to print the current PDF page
 
 Only used if enablePageSharing returns NO
 
 default: YES
 */
- (BOOL)enablePagePrint;

/**
 Add an button to speak the current article
 
 default: YES
 */
- (BOOL)enableArticleListening;

/**
 The voice identifiers to use for article listening, if available on the device, sorted by priority
 
 See AVSpeechSynthesisVoice
 
 default: nil
 */
- (nullable NSArray<NSString *> *)preferredVoiceIdentifiersForArticleListening;

/**
 The language to use for article listening (fallback from preferredVoiceIdentifiersForArticleListening)
 
 default: fr-FR
 */
- (nonnull NSString *)preferredLanguageCodeForArticleListening;

/**
 Enable article sharing
 
 default: YES if there is at least one sharing plugin configured
 */
- (BOOL)enableArticleSharing;

/**
 The article sharing plugins, conforming to MLPDFRArticleSharingPlugin
 
 default: empty
 */
- (nonnull NSArray<id <MLPDFRArticleSharingPlugin>> *)articleSharingPlugins;

/**
 Enable article printing
 
 default: NO
 */
- (BOOL)enableArticlePrint;

/**
 Use inline player for audio boxes
 
 default: NO
 */
- (BOOL)useMinifiedAudioPlayer;

/**
 Allow minified video player for video boxes
 The app must also include the Audio background mode capability
 
 default: NO
 */
- (BOOL)allowsPictureInPicturePlayback;

#pragma mark - Sections

/**
 Display sections in the railway controller
 
 default: NO
 */
- (BOOL)enableSections;

/**
 In reader mode, use page numbers from the PDF as sections
 
 default: YES
 */
- (BOOL)usePageNumbersAsArticleSections;

/**
 Group sections by name in summary
 
 default: YES
 */
- (BOOL)mergeSections;

#pragma mark - Theme

/**
 The tint color for the navigation bar
 
 default: systemBackground/white
 */
- (nullable UIColor *)navigationTintColor;

/**
 The text color for the navigation bar
 
 default: label/black
 */
- (nonnull UIColor *)navigationTextColor;

/**
 The status bar style
 
 default: UIStatusBarStyleDefault
 */
- (UIStatusBarStyle)statusBarStyle;

/**
 The border color of the selected page in the railway
 
 default: secondaryLabel/black
 */
- (nonnull UIColor *)selectedPageBorderColor;

/**
 The text color of the selected section in the railway
 
 default: navigationTintColor
 */
- (nonnull UIColor *)selectedSectionTextColor;

/**
 The background color of the selected section in the railway
 
 default: navigationTextColor
 */
- (nullable UIColor *)selectedSectionBackgroundColor;

/**
 The background corner radius of the selected section in the railway
 
 default: 3
 */
- (CGFloat)selectedSectionBackgroundCornerRadius;

/**
 The text color of a deselected section in the railway
 
 default: navigationTextColor
 */
- (nonnull UIColor *)deselectedSectionTextColor;

#pragma mark - Customization

/**
 The displayed title of the current document
 
 default: document title
 */
- (nullable NSString *)navigationTitle;

/**
 The displayed subtitle of the current document
 
 default: document date
 */
- (nullable NSString *)navigationSubTitle;

/**
 Override label for a page in the railway
 
 default: originalLabel
 */
- (nonnull NSString *)railwayPageLabelForOriginalLabel:(nonnull NSString *)originalLabel atPageNumber:(NSInteger)pageNumber;

/**
 The optional top view of the article list
 
 default: nil
 */
- (nullable UIView *)topViewForArticleList;

/**
 The height of the top view of the article list
 
 default: 200
 */
- (NSInteger)heightOfTopViewForArticleListWithParentWidth:(NSInteger)parentWidth;

/**
 The text of the back button of the navigation bar
 
 default: "Back"
 */
- (nonnull NSString *)navigationBackButtonText;

/**
 The text of the articles button of the navigation bar
 
 default: "Articles"
 */
- (nonnull NSString *)navigationArticlesButtonText;

/**
 The image of the articles button of the navigation bar
 
 default: article-mode
 */
- (nullable UIImage *)navigationArticlesButtonImage __deprecated_msg("See the docs for overriding icons");

/**
 Use navigationArticlesButtonImage instead of navigationArticlesButtonText
 
 default: YES
 */
- (BOOL)useNavigationArticlesButtonImage;

/**
 Starting with iOS 13, using standard SF symbols for icons when available and not overriden.

 default: YES
 */
- (BOOL)useSystemIcons;

@end
