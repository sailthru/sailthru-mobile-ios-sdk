// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "Marigold",
    platforms: [
        .iOS("15.6")
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "Marigold",
            targets: ["Marigold"]),
        .library(
            name: "MarigoldExtension",
            targets: ["MarigoldExtension"])
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(
            name: "Marigold",
            path: "Marigold.xcframework"
        ),
        .binaryTarget(
            name: "MarigoldExtension",
            path: "MarigoldExtension.xcframework"
        )
    ]
)
