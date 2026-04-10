# AvatarKit

SwiftUI view that renders Apple's Animoji characters driven by face tracking data.

Uses Apple's private AvatarKit framework via ObjC runtime. Works on physical iOS devices with TrueDepth camera.

## Usage

```swift
import AvatarKit

// From any face tracking source
let tracking = AvatarFaceTracking(
    blendshapes: ["jawOpen": 0.5, "eyeBlinkLeft": 0.8],
    headRotation: myQuaternion,
    isTracking: true
)

AvatarView(animoji: "skull", tracking: tracking)
```

### With ARKit

```swift
import ARKit
import AvatarKit

// In your ARSession delegate
func session(_ session: ARSession, didUpdate frame: ARFrame) {
    if let face = frame.anchors.first(where: { $0 is ARFaceAnchor }) as? ARFaceAnchor {
        tracking = AvatarFaceTracking(faceAnchor: face)
    }
}

// In your SwiftUI view
AvatarView(animoji: "skull", tracking: tracking)
```

### With HumanSenseKit

```swift
import HumanSenseKit
import AvatarKit

// HumanSenseKit provides blendshapes + head rotation
let tracking = AvatarFaceTracking(
    blendshapes: humanSense.blendshapes,
    headRotation: humanSense.headRotation,
    isTracking: humanSense.isTracking
)

AvatarView(animoji: "tiger", tracking: tracking)
```

## Available Animoji

```swift
AvatarView.availableAnimoji
// ["alien", "bear", "boar", "cat", "chicken", "cow", "dog", "dragon",
//  "fox", "ghost", "giraffe", "koala", "lion", "monkey", "mouse",
//  "octopus", "owl", "panda", "pig", "poo", "rabbit", "robot",
//  "shark", "skull", "tiger", "trex", "unicorn"]
```

## Requirements

- iOS 17+
- Physical device with TrueDepth camera (Face ID)
- Not available on Simulator

## Installation

```swift
// Package.swift
dependencies: [
    .package(url: "https://github.com/momomo-agent/AvatarKit.git", from: "0.1.0")
]
```

## ⚠️ Private Framework

This package uses Apple's private AvatarKit framework. It will not pass App Store review. Use for personal projects, research, or internal tools only.
