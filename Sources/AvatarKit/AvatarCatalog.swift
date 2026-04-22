import Foundation
import UIKit
import simd

// MARK: - Avatar Catalog

/// Discovers and loads available avatar characters.
public final class AvatarCatalog: @unchecked Sendable {
    
    /// A loadable avatar character.
    public struct Character: Identifiable, Sendable {
        public let id: String
        public let name: String
        public let type: CharacterType
        
        public enum CharacterType: Sendable {
            case animoji
            case memoji
        }
    }
    
    /// All available Animoji characters.
    public static func animojiCharacters() -> [Character] {
        guard let cls = NSClassFromString("AVTAnimoji") else { return [] }
        
        let sel = NSSelectorFromString("availableAnimojiNames")
        guard (cls as AnyObject).responds(to: sel),
              let names = (cls as AnyObject).perform(sel)?.takeUnretainedValue() as? [String]
        else { return [] }
        
        return names.map { Character(id: $0, name: $0.capitalized, type: .animoji) }
    }
    
    /// Load the head diffuse texture for an Animoji character.
    /// Returns nil if the texture is not found.
    public static func headTexture(for characterID: String) -> UIImage? {
        // AvatarKit.framework/animoji/{name}/{name}_head_DIFFUSE.heic
        let bundle = Bundle(path: "/System/Library/PrivateFrameworks/AvatarKit.framework")
        let path = bundle?.path(forResource: "\(characterID)_head_DIFFUSE",
                                ofType: "heic",
                                inDirectory: "animoji/\(characterID)")
        guard let path else { return nil }
        return UIImage(contentsOfFile: path)
    }
}
