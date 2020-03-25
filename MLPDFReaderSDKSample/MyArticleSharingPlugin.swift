//
//  MyArticleSharingPlugin.swift
//  MLPDFReaderSDKSample
//
//  Created by Jeremy FAIVRE on 08/09/2015.
//  Copyright (c) 2015 miLibris. All rights reserved.
//

import MLPDFReaderSDK
import UIKit

class MyArticleSharingPlugin: NSObject, MLPDFRArticleSharingPlugin {

    var actionName: String {
        return "Custom"
    }

    func share(_ article: MLPDFRSharingArticle,
               from viewController: UIViewController,
               barButtonItem: UIBarButtonItem) {
        let alertController = UIAlertController(
            title: "Sharing",
            message: "This is a custom article sharing plugin displaying an alert dialog.",
            preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "OK", style: .default))
        viewController.present(alertController, animated: true)
    }

}
