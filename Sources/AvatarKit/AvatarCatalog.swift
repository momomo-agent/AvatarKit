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
    public static func headTexture(for characterID: String) -> UIImage? {
        guard let cls = NSClassFromString("AVTAnimoji") else { return nil }
        let bundle = Bundle(for: cls)
        let path = bundle.bundlePath + "/animoji/\(characterID)/\(characterID)_head_DIFFUSE.heic"
        return UIImage(contentsOfFile: path)
    }
}
