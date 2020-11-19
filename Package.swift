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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/1.2.0/MLPDFReaderSDK.xcframework.zip",
            checksum: "41b65d79ac5f1db1e0861fb4b286baf38e1ac52090c394fbfa526b0282609fba"
        ),
    ]
)
