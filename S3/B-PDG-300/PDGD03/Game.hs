{-
-- EPITECH PROJECT, 2024
-- Day03
-- File description:
-- Game
-}

data Item = Sword | Bow | MagicWand deriving Eq

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving Eq

class HasItem i where
    getItem :: i -> Maybe Item
    hasItem :: i -> Bool
    hasItem x = case getItem x of
        Just _ -> True
        _ -> False


instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch item) = item


instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton a) = "skeleton holding a " ++ show a
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just a)) = "witch holding a " ++ show a

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob 
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create mob = case mob of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    _ -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))
