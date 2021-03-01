//
//  ShareLinkToWebKiosk.swift
//  MLPDFReaderSDKSample
//
//  Created by Maxime Le Moine on 01/03/2021.
//

import Foundation
import MLPDFReaderSDK

/// A sharing plugin that shares the web kiosk URL of an article. The user can use the social app of his/her choice.
///
/// This feature must be enabled on the web kiosk. Contact miLibris support for more info.
class ShareLinkToWebKiosk: NSObject, MLPDFRArticleSharingPlugin {

    /// The URL of the web kiosk
    let kioskURL: URL

    init(kioskURL: URL) {
        self.kioskURL = kioskURL
    }

    // MARK: MLPDFRArticleSharingPlugin

    var actionName: String {
        return "Share link to web kiosk"
    }

    func share(_ article: MLPDFRSharingArticle, from viewController: UIViewController, barButtonItem: UIBarButtonItem) {
        guard let readerSession = ReaderSession.current else {
            print("Reader context not configured")
            return
        }

        // Example: https://www.examplekiosk.milibris.com/share/article/bbc8c404-c945-4518-924a-c766cdd399d8/1958816d-b3c4-4574-945d-fc8ec12cb16a
        let sharingURL = kioskURL
            .appendingPathComponent("share/article")
            .appendingPathComponent(readerSession.issueMID)
            .appendingPathComponent(article.mid)

        let activityViewController = UIActivityViewController(activityItems: [sharingURL], applicationActivities: nil)

        activityViewController.modalPresentationStyle = .popover
        viewController.present(activityViewController, animated: true, completion: nil)

        // Get the popover presentation controller and configure it.
        if let presentationController = activityViewController.popoverPresentationController {
            presentationController.permittedArrowDirections = .any
            presentationController.barButtonItem = barButtonItem
        }
    }

}
