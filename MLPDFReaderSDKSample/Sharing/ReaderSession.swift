//
//  ReaderSession.swift
//  MLPDFReaderSDKSample
//
//  Created by Maxime Le Moine on 01/03/2021.
//

import Foundation

/// A class used to retain data about an edition opened in the reader.
final class ReaderSession {

    static var current: ReaderSession?

    let issueMID: String

    init(issueMID: String) {
        self.issueMID = issueMID
    }

}
