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
            url: "https://github.com/miLibris/ios-milibris-pdf-reader-sdk/releases/download/spm/MLPDFReaderSDK.xcframework.zip",
            checksum: "f5e0e9df6ed8823afcc657d1d893f9da0cb74197a9ee8239074b765560d4ee3e"
        ),
    ]
)
