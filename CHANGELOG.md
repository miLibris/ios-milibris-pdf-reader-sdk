# MLPDFReaderSDK iOS changelog

### v1.2.0
19/11/2020

- Update deployment target to iOS 11
- Requires Xcode 12 or later

- Add support for Swift Package Manager
- Provide SDK as an XCFramework for CocoaPods and Swift Package Manager. A fat framework is still provided for Carthage compatibility.

### v1.1.0
23/09/2020

- Add configuration *enableDoublePages* (true by default) to enable/disable double pages in landscape

### v1.0.0
15/07/2020

The SDK is now distributed through CocoaPods and Carthage. Instructions for installation, usage, and a sample project can be found at https://github.com/miLibris/ios-milibris-pdf-reader-sdk.

SDK clients will now require a licence key for each of their applications; this key is provided by miLibris.

### v0.26.0
30/01/2020

- Internal changes

### v0.25.1
13/12/2019

- Fix integration error message display

### v0.25.0
11/12/2019

- Build SDK on Xcode 11.2
- Internal changes

### v0.24.1
22/10/2019

- Fix integration error message not staying visible

### v0.24.0
18/10/2019

- Requires Xcode 11 or later
- Update for Xcode 11, iOS 13

**Improvements**

- Add dark mode support for iOS 13
- Use SFSymbols standard icons on iOS 13
- Fix text size control on iOS 13
- Update summary design

### v0.23.3
11/09/2019

**Improvements**

- Fix tiling crash on iOS 13

### v0.23.2
01/07/2019

**Improvements**

- Add missing translations

### v0.23.1
20/06/2019

**Improvements**

- Show top bar by default when VoiceOver is activated
- Add accessibility labels on icon actions
- Add VoiceOver interaction for arrow button
- Add VoiceOver interaction for PDF pages
- Add VoiceOver interaction for thumbnail railway

### v0.23.0
04/06/2019

- Allow client app to override localized strings; see README

### v0.22.3
03/05/2019

**Improvements**

- Fix multimedia content closing when rotating device

### v0.22.2
05/04/2019

- Add documentation for overriding icons & do not compile them

### v0.22.1
03/04/2019

- Build SDK with Xcode 10.2

### v0.22.0
01/03/2019

**Improvements**

- Handle custom PDF rotation

### v0.21.0
11/01/2019

- Internal changes

### v0.20.4
08/01/2019

- Fix docs
- Internal changes

### v0.20.3
07/01/2019

- Improve error safety
- Fix web completion handler called twice
- Add nullability annotations, unavailable initializers
- Internal changes

### v0.20.2
29/11/2018

- Internal changes

### v0.20.1
16/11/2018

- Build SDK with Xcode 10.1

### v0.20.0
06/11/2018

**Breaking**

- It is no longer necessary to retain the MLPDFReader instance. It is now retained by MLPDFRReaderViewController, which must be initialized with the reader.
- MLPDFReader initializer now throws instead of returning nil if an error occurs (for example, if the provided path does not contain a valid unpacked release).
- The signature of the delegate method used to close the reader view controller has changed in order to provide the view controller that should be dismissed.

**Improvements**

- Purge MLFoundation cache when closing reader

### v0.19.0
05/10/2018

**Breaking**

- The SDK is now distributed as a dynamic framework; see the README for more info

**Improvements**

- Remove SDWebImage dependency, replace with memory cache managed by the MLPDFReader instance
- Use an asset catalog
- Fix documentation warnings

### v0.18.0
20/09/2018

- Update deployment target to iOS 10

**Improvements**

- Improve KVO type safety

### v0.17.1
12/09/2018

**Improvements**

- Fix summary sorting
- Improve closest article detection
- Fix long press animation regression
- Fix current page state

### v0.17.0
30/08/2018

**Features**

- Handle reverse navigation

### v0.16.2
08/08/2018

**Improvements**

- Fix crash on invalid layout
- Fix dismissing of reader in sample and docs

### v0.16.1
03/05/2018

- Internal changes

### v0.16.0
16/04/2018

**Features**

- Expose delegate stat methods

### v0.15.2
21/12/2017

**Improvements**

- Fix crash on null Brightcove response

### v0.15.1
29/11/2017

**Improvements**

- Fix railway layout on landscape iPhone X
- Fix navigation bar layout on iOS 11 landscape iphones
- Delete Kewego widget

### v0.15.0
09/11/2017

- Internal changes

### v0.14.2
07/11/2017

**Improvements**

- Fix font size factor not working
- Fix font size buttons highlighted attributes

### v0.14.1
04/10/2017

- Change SDK integration error message

### v0.14.0
25/09/2017

- Now requires Xcode 9 or larger, iOS 9 or larger

**Improvements**

- Compatibility with iOS 11 and iPhone X

### v0.13.0
18/08/2017

**Breaking**

- Refactor article sharing plugins protocol, which now passes an object instead of a dictionary

**Improvements**

- Use an object instead of a dictionary for articles
- Code cleanup

### v0.12.5
10/08/2017

- Do not use SDWebImage for zoom
- Internal changes

### v0.12.4
02/08/2017

- Internal changes

### v0.12.3
25/07/2017

- Whait until the reader is displayed before hiding the status bar

### v0.12.2
18/07/2017

- Remove animation when opening the reader on an article

### v0.12.1
17/07/2017

- Internal changes

### v0.12.0
20/06/2017

- Internal changes

### v0.11.3
14/06/2017

- Revert to SDWebImage v3.8.2

### v0.11.2
18/05/2017

- Update SDWebImage to v4.0.0

### v0.11.1
10/04/2017

**Bug fixes**

- Do not crash on article listening in iOS 8

### v0.11.0
10/04/2017

**Features**

- Add configuration *preferredVoiceIdentifiersForArticleListening* to customize the speech voice by preferred identifiers

### v0.10.3
30/03/2017

**Bug fixes**

- Open target="_blank" links in Safari (instead of doing nothing)

### v0.10.2
29/03/2017

- Add option to enable picture in picture video playback , disable by default
- Fix case in import

### v0.10.1
06/03/2017

**Bug fixes**

- Remove long press gesture when article mode is disabled

### v0.10.0
01/03/2017

**Breaking changes**

- ViewController-based status bar appearance is now required in the client application

**Features**

- UI improvements: article mode, status bar, enrichments
- Apply theme on article mode and enrichments
- Add picture-in-picture support for video enrichments

**Code**

- Modernize iOS API usage
- Cleanup dependencies

**SDK**

- Include bitcode in SDK
- Add a local podspec to allow installation with CocoaPods

**Dependencies**

- Update MLFoundation to 1.2.0

### v0.9.4
23/02/2017

**Bug fixes**

- Fix crash when there is only one page in a publication
- Fix SDK article sharing header

### v0.9.3
15/02/2017

**Bug fixes**

- Fix crash on article print

**Code**

- Change MLPDFRArticleSharingPlugin import in configuration

### v0.9.2
07/02/2017

**Code**

- Change MLPDFRArticleSharingPlugin import in configuration

### v0.9.1
03/01/2017

**Features**

- Add article sharing dictionary key *kMLPDFRArticleSharingArticleContentKey*

### v0.9.0
03/01/2017

**Features**

- Expose article sharing dictionary keys:
  - *kMLPDFRArticleSharingEditionTitleKey*
  - *kMLPDFRArticleSharingEditionSubtitleKey*
  - *kMLPDFRArticleSharingArticleMIDKey*
  - *kMLPDFRArticleSharingArticleTitleKey*
  - *kMLPDFRArticleSharingArticleURLKey*
- Remove deprecated article sharing dictionary keys:
  - *mailTitle* (use *kMLPDFRArticleSharingEditionTitleKey* and *kMLPDFRArticleSharingEditionSubtitleKey* instead)
  - *MLArticleSharingArticleIssueKey* (use *kMLPDFRArticleSharingEditionTitleKey* and *kMLPDFRArticleSharingEditionSubtitleKey* instead)
  - *MLArticleSharingArticleURLKey* (use *kMLPDFRArticleSharingArticleURLKey* instead)
  - *MLArticleSharingArticleTitleKey* (use *kMLPDFRArticleSharingArticleTitleKey* instead)
  - *MLArticleSharingArticleMailTitleKey* (use *kMLPDFRArticleSharingEditionTitleKey* and *kMLPDFRArticleSharingEditionSubtitleKey* instead)
  - *MLArticleSharingArticleContentKey* (read the file located at *kMLPDFRArticleSharingArticleURLKey* instead)

**Code**

- Annotate interface for Swift
- Modernize Objective-C syntax

### v0.8.0
08/11/2016

**Features**

- Change article list background color from black to white
- Do not use PDF rendering while the user is scrolling pages ; this improves performances and mitigates an iOS 10 memory leak

**Dependencies**

- Update SDWebImage to 3.8.2

### v0.7.4
08/11/2016

**Bug fixes**

- Fix a crash that would occur when receiving an invalid geometry in grouping scroll view

### v0.7.3
28/10/2016

**Bug fixes**

- Fix a bug where the paragraphs of the article view would sometimes be displayed at the wrong font size

### v0.7.1
30/09/2016

**Bug fixes**

- Fix a regression in the calculation of status bar height
- Fix article speech rate for iOS 10
- Decrease queue priority of railway thumbnails loading

**Dependencies**

- Update MLFoundation to 1.1.0

### v0.7.0
22/09/2016

- Begin changelog
