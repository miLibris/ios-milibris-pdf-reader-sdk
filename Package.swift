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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/v1.4.1/MLPDFReaderSDK.xcframework.zip",
            checksum: "06393db968cbeafed1f90a5f415ca7402adc435b384a063ffc4d299cf086e923"
        ),
    ]
)
