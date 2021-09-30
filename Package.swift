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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/v1.4.0/MLPDFReaderSDK.xcframework.zip",
            checksum: "dbc33a0ff5977059f3980de46b495030e9a86c66bc065831f2bf2c940526e5e5"
        ),
    ]
)
