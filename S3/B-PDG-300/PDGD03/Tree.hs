{-
-- EPITECH PROJECT, 2024
-- Day03
-- File description:
-- Game
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving Show

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree x (Node left y right) | y <= x = Node left y (addInTree x right)
                                | y > x = Node (addInTree x left) y right

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node left y right) = Node (fmap f left) (f y) (fmap f right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = (addInTree x (listToTree xs))
