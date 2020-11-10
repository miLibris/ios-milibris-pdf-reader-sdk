# MLPDFReaderSDK

MLPDFReaderSDK is the miLibris reading SDK (previously called MLReader). It includes the MLFoundation library allowing to unpack miLibris contents.

* [Setup](#setup)
    * [Prerequisites](#prerequisites)
    * [Installation via CocoaPods](#installation-via-cocoapods)
    * [Installation via Carthage](#installation-via-carthage)
    * [Manual installation](#manual-installation)
    * [Migrating to v1.0](#migrating-to-v10)
    * [Migrating to v0.20](#migrating-to-v020)
    * [Migrating to v0.19](#migrating-to-v019)
* [Implementation](#implementation)
    * [Usual workflow](#usual-workflow)
    * [Unpack a complete archive with MLFoundation](#unpack-a-complete-archive-with-mlfoundation)
    * [Read unpacked contents](#read-unpacked-contents)
    * [Sample project](#sample-project)
    * [Overriding icons](#overriding-icons)
    * [Overriding strings](#overriding-strings)

## Setup

### Prerequisites

MLPDFReaderSDK requires iOS 11 or later, Xcode 12 or later. The SDK is provided as an XCFramework and a dynamic framework.

Every app using the SDK must be configured with a licence key provided by miLibris. A licence key cannot be used in more than one application.

* In your Xcode project, open your main target *Info.plist*

* Add a new key named *MLPDFReaderSDKLicenceKey* of type *String*.

* In the value field, add the licence key provided by miLibris.

### Installation via CocoaPods (requires CocoaPods 1.9 or greater)

* Add the following line in your *Podfile*:

`pod 'MLPDFReaderSDK', '~> 1.0'`

* Run `pod install`

### Installation via Carthage

* Add the following line in your *Cartfile*:

`binary "https://raw.githubusercontent.com/miLibris/ios-milibris-pdf-reader-sdk/master/MLPDFReaderSDK.json" ~> 1.0`

* Run `carthage update`

### Installation via Swift Package Manager

* In your Xcode project, select *File* > *Swift Packages* > *Add Package Dependency...*

* In the URL field, paste *https://github.com/miLibris/ios-milibris-pdf-reader-sdk* and select *Next*

* Select the update rule: "Up to next major" from the current version

* Add the product "MLPDFReaderSDK" to your app target

* Add *MLPDFReaderSDK.xcframework* into your project's *Embedded Content* section in the project editor.

### Manual installation

* Download and unzip the SDK: https://seafile.milibris.com/d/5fabcc8fe9/files/?p=/MLPDFReaderSDK_vspm.xcframework.zip&dl=1

* Copy *MLPDFReaderSDK.xcframework* in your project direectory.

* Add *MLPDFReaderSDK.xcframework* into your project's *Embedded Content* section in the project editor.

### Migrating to v1.0

* Add your app's licence key to your project's Info.plist, as detailed in *Prerequisites*.
* If you are using CocoaPods to integrate the SDK:
  - In your *Podfile*, replace `pod 'MLPDFReaderSDK', :path => 'MLPDFReaderSDK'` with `pod 'MLPDFReaderSDK', '~> 1.0'`
  - Delete the directory *MLPDFReaderSDK* that you previously downloaded manually.
  - Run `pod update`.

### Migrating to v0.20

* It is no longer necessary to retain the MLPDFReader instance. It is now retained by MLPDFRReaderViewController, which must be initialized with the reader.
* MLPDFReader initializer now throws instead of returning nil if an error occurs (for example, if the provided path does not contain a valid unpacked release).
* The signature of the delegate method used to close the reader view controller has changed in order to provide the view controller that should be dismissed.

### Migrating to v0.19

* SDWebImage is no longer needed as a dependency.
* If your app uses Swift, you can remove MLPDFReaderSDK imports from your bridging header.
* In your source files, import the SDK with `import MLPDFReaderSDK` (Swift) or `#import <MLPDFReaderSDK/MLPDFReaderSDK.h>` (ObjC).
* If you previously integrated MLPDFReaderSDK manually, Delete the following files and remove them from your Xcode project:
    * MLPDFReader.h
    * MLPDFReaderBaseConfiguration.h
    * MLPDFRArticleSharingPlugin.h
    * MLPDFRSharingArticle.h
    * MLFoundation.h
    * MLFoundationBase.h
    * MLFoundationBridge.h
    * MLProductInfo.h
    * MLProductSource.h
    * libMLPDFReader.a
    * libMLFoundation.a
    * libSDWebImage.a (if present)

## Implementation

### Usual workflow

In order to read a content, your application will likely implement the following steps:

* Download a complete archive (with the *.complete extension) from the miLibris platform
* Unpack the archive using MLFoundation
* Launch MLPDFReader to read the unpacked contents

### Unpack a complete archive with MLFoundation

A complete archive can be easily unpacked with the MLFoundationBridge class:

    import MLPDFReaderSDK

    // ...

    do {
        try MLArchive.extract(archiveURL, inDirectory: releaseURL)
    } catch {
        print("Error when unpacking content: \(error)")
    }

### Read unpacked contents

Once unpacked, you can open the content with MLPDFReader and a standard UIViewController instance to display:

    do {
        // Initialize the PDF Reader to open the context
        let reader = try MLPDFReader(contentURL: URL(fileURLWithPath: releasePath), config: ReaderConfiguration(), delegate: self)

        // Create a view controller and display it
        let readerViewController = MLPDFRReaderViewController(pdfReader: reader)
        self.present(readerViewController, animated: true)
    } catch {
        print("Error initializing reader: \(error)")
    }

An MLPDFReaderDelegate instance must be provided in order to be able to close the reader controller once the user presses the *back* button. When doing so, the *pdfReader:didFinishReading:* method will be called. **It is the responsibility of your delegate to close the reader view controller**.

    func pdfReader(_ pdfReader: MLPDFReader, didFinishReading readerViewController: MLPDFRReaderViewController) {
        self.dismiss(animated: true)
    }

### Sample project

A sample project is provided to help you implement the reader integration. It contains an example to unpack a complete archive and to open if with MLPDFReader.

If your miLibris content has articles, you can implement your own sharing solution by implementing the MLPDFRArticleSharingPlugin protocol. A basic example is also provided in the sample project.

* If you use CocoaPods, run `pod install` in the *sample_cocoapods* directory and then open *MLPDFReaderSDKSample.xcworkspace*.
* If you use Carthage, run `carthage update` in the *sample_carthage* directory and then open *MLPDFReaderSDKSample.xcodeproj*.

### Overriding icons

The client app can override the icons used by the SDK. To do so:

* In your main target Resources directory (or if you do not have one, your main target directory), create a directory named *MLPDFReader.extend.bundle*.
* Add this directory to your Xcode project. Make sure its target membership is set to your app target, and that it is recognized by Xcode as a resource bundle (its icon should be a white cube).
* Add your custom icons to this directory. You do not need to provide all icons. They should be named like the default icons used by the SDK and have the *.png* extension. Use *@2x* and *@3x* for higher resolution images.
* Build and run your project. For each icon, the SDK will check if it exists in your custom bundle, or fall back to the default icon.

The icons used by the SDK can be found in *MLPDFReaderSDK.framework/MLPDFReader.bundle*.

### Overriding strings

The client app can override the localized strings used by the SDK. To do so:

* In your main target in Xcode, create a new strings file named *MLPDFReader.strings*.
* Localize it in the languages supported by your application.
* Add any strings you want to override to this file.

The strings used by the SDK can be found in *MLPDFReaderSDK.framework/MLPDFReader.bundle*.
