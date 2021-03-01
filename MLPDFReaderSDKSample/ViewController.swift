//
//  ViewController.swift
//  MLPDFReaderSDKSample
//
//  Created by Jeremy FAIVRE on 08/09/2015.
//  Copyright (c) 2015 miLibris. All rights reserved.
//

import MLPDFReaderSDK
import UIKit

class ViewController: UIViewController, MLPDFReaderDelegate {

    let releaseURL = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0]
        .appendingPathComponent("sample")

    override func viewDidLoad() {
        super.viewDidLoad()

        guard let archiveURL = Bundle.main.url(forResource: "sample", withExtension: "complete") else {
            fatalError("sample.complete not found in bundle")
        }
        try? FileManager.default.removeItem(at: releaseURL)

        // Unpack .complete
        do {
            try MLArchive.extract(archiveURL, inDirectory: releaseURL)
        } catch {
            print("Error when unpacking content: \(error)")
        }

    }

    @IBAction func openReader() {
        do {
            // Initialize the PDF Reader to open the context
            let reader = try MLPDFReader(contentURL: releaseURL, config: ReaderConfiguration(), delegate: self)

            // Retain a session with the current reader session information.
            // This session will be accessible from sharing plugins.
            ReaderSession.current = ReaderSession(
                // replace with the issue MID that is being read (from miLibris API)
                issueMID: "bbc8c404-c945-4518-924a-c766cdd399d8"
            )

            // Create a view controller and display it
            let readerViewController = MLPDFRReaderViewController(pdfReader: reader)
            present(readerViewController, animated: true)
        } catch {
            print("Error initializing reader: \(error)")
        }
    }

    // MARK: MLPDFReaderDelegate

    func pdfReader(_ pdfReader: MLPDFReader, didMoveToPageNumber pageNumber: Int) {
        print("did move to page: \(pageNumber)")
    }

    func pdfReader(_ pdfReader: MLPDFReader, didOpen article: MLPDFRSharingArticle) {
        print("did open article: \(article.title ?? "()")")
    }

    func pdfReader(_ pdfReader: MLPDFReader, didFinishReading readerViewController: MLPDFRReaderViewController) {
        self.dismiss(animated: true)
    }

}
