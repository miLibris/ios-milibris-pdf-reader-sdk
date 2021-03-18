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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/v1.3.0/MLPDFReaderSDK.xcframework.zip",
            checksum: "c82fbb1cb3772bb3bcf69c22551fcde2eee68291f5e810fcdd781f734441db7f"
        ),
    ]
)
