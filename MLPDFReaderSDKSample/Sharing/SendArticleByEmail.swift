//
//  SendArticleByEmail.swift
//  MLPDFReaderSDKSample
//
//  Created by Maxime Le Moine on 01/03/2021.
//

import Foundation
import MessageUI
import MLPDFReaderSDK

/// A sharing plugin that sends the content of an article by email.
///
/// This plugin only works if the user has an account configured in the default mail app.
class SendArticleByEmail: NSObject, MLPDFRArticleSharingPlugin, MFMailComposeViewControllerDelegate {

    // MARK: MLPDFRArticleSharingPlugin

    var actionName: String {
        return "Send article by email"
    }

    func share(_ article: MLPDFRSharingArticle, from viewController: UIViewController, barButtonItem: UIBarButtonItem) {
        guard MFMailComposeViewController.canSendMail() else {
            let alertController = UIAlertController(
                title: "Unable to send mail",
                message: "You must have an account configured in the Mail app.",
                preferredStyle: .alert
            )
            let defaultAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alertController.addAction(defaultAction)
            viewController.present(alertController, animated: true)
            return
        }

        let composer = MFMailComposeViewController()
        composer.setSubject(mailSubject(article: article) ?? "")
        composer.setMessageBody(mailBody(article: article), isHTML: true)

        composer.mailComposeDelegate = self
        viewController.present(composer, animated: true, completion: nil)
    }

    // MARK: MFMailComposeViewControllerDelegate

    func mailComposeController(
        _ controller: MFMailComposeViewController,
        didFinishWith result: MFMailComposeResult,
        error: Error?
    ) {
        controller.dismiss(animated: true)
    }

    // MARK: Private

    private func mailSubject(article: MLPDFRSharingArticle) -> String? {
        // article_title (edition_title, edition_subtitle)
        if let articleTitle = article.title {
            if let editionTitle = article.editionTitle {
                if let editionSubtitle = article.editionSubtitle {
                    return "\(articleTitle) (\(editionTitle), \(editionSubtitle))"
                } else {
                    return "\(articleTitle) (\(editionTitle))"
                }
            } else {
                return articleTitle
            }
        } else {
            return nil
        }
    }

    private func mailBody(article: MLPDFRSharingArticle) -> String {
        var content = "I thought you might be interested in this article:<br/><br/>"
        if let articleTitle = article.title {
            content.append("\(articleTitle)<br/><br/>")
        }
        if let htmlContent = article.htmlContent() {
            content.append("\(htmlContent)")
        }
        return content
    }

}
