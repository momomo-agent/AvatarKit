// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "AvatarKit",
    platforms: [.iOS(.v17)],
    products: [
        .library(name: "AvatarKit", targets: ["AvatarKit"]),
    ],
    targets: [
        .target(
            name: "ObjCBridge",
            publicHeadersPath: "include"
        ),
        .target(
            name: "AvatarKit",
            dependencies: ["ObjCBridge"]
        ),
    ]
)
