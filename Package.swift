// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "MLPDFReaderSDK",
    platforms: [.iOS(.v11)],
    products: [
        .library(name: "MLPDFReaderSDK",targets: ["MLPDFReaderSDK"]),
    ],
    targets: [
        .binaryTarget(
            name: "MLPDFReaderSDK",
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/spm_1/MLPDFReaderSDK.xcframework.zip",
            checksum: "a7de04ae38f68768ca594d8f577dcfc8fcd8094d5f7a79168eccf77a7baf17f9"
        ),
    ]
)
