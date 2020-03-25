//
//  ReaderConfiguration.swift
//  MLPDFReaderSDKSample
//
//  Created by Jeremy FAIVRE on 08/09/2015.
//  Copyright (c) 2015 miLibris. All rights reserved.
//

import MLPDFReaderSDK
import UIKit

class ReaderConfiguration: MLPDFReaderBaseConfiguration {

    override func articleSharingPlugins() -> [MLPDFRArticleSharingPlugin] {
        // Custom article sharing plugin
        return [MyArticleSharingPlugin()]
    }

}
