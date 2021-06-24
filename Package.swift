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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/v1.3.1/MLPDFReaderSDK.xcframework.zip",
            checksum: "3d1dce143fac4fff44d7926f8faff9b649a6fedcefa11748d263c9f8580b13e5"
        ),
    ]
)
