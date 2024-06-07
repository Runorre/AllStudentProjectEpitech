{-
-- EPITECH PROJECT, 2024
-- Day02
-- File description:
-- DoOp
-}

import Data.Char

myElem :: Eq a => a -> [ a ] -> Bool
myElem  _ [] = False
myElem y (x:_) | y == x = True
myElem y (_:xs) = myElem y xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (div x y)

safeNth :: [ a ] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) b
    | b < 0 =  Nothing
    | b /= 0 = safeNth xs (b - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc x = fmap (+1) x

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x ((y, z):ys) | x == y = Just z
                    | x /= y = myLookup x ys

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _  _ Nothing = Nothing
maybeDo func x y = fmap func x <*> y

readInt :: [ Char ] -> Maybe Int
readInt [] = Nothing
readInt str | all isDigit str = Just (read str)
readInt _ = Nothing

getLineLength :: IO Int
getLineLength = fmap length getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

printBox :: Int -> IO ()
printBox x | x <= 0 = return ()
printBox 1 = putStrLn "++"
printBox x = putStrLn t >> putStr m >> putStrLn t
    where
        t = "+" ++ concat (replicate ((x * 2) - 2) "-") ++ "+"
        m = concat $ replicate (x - 2) onlineMiddle
        onlineMiddle = ("|" ++ (concat $ replicate ((x * 2) - 2) " ") ++ "|\n")

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines x = do 
    line <- getLine
    next <- concatLines (x - 1)
    return (line ++ next)

getInt :: IO ( Maybe Int )
getInt = do
    line <- getLine
    return (readInt line)


