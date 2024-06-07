{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- main
-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use list literal pattern" #-}
{-# HLINT ignore "Use if" #-}
{-# HLINT ignore "Use foldr" #-}
{-# HLINT ignore "Redundant bracket" #-}

import System.Environment
import System.Exit
import Data.Char
import Swap

getList :: String -> [String]
getList = words

checkList :: [String] -> Bool
checkList [] = True
checkList (x:xs) | length x < 2 || length x > 3 = False
checkList (x:xs) = case x of
    "sa" -> checkList xs
    "sb" -> checkList xs
    "sc" -> checkList xs
    "pa" -> checkList xs
    "pb" -> checkList xs
    _ -> checkList2 (x:xs)

checkList2 :: [String] -> Bool
checkList2 [] = True
checkList2 (x:xs) = case x of
    "ra" -> checkList xs
    "rb" -> checkList xs
    "rr" -> checkList xs
    "rra" -> checkList xs
    "rrb" -> checkList xs
    "rrr" -> checkList xs
    _ -> False


checkInt :: [String] -> Bool
checkInt [] = False
checkInt ((x:ys):[]) | not (all isDigit ys) && x /= '-' = False
checkInt ((x:ys):[]) | all isDigit ys = True
checkInt ((x:ys):xs) | not (all isDigit ys) && x /= '-' = False
checkInt ((x:ys):xs) | all isDigit ys  = checkInt xs

checkSort :: Ord a => ([a], [a]) -> Bool
checkSort (x, []) | length x <= 1 = True
checkSort (x:y:xs, []) | x <= y = checkSort (y:xs, [])
                    | x > y = False
checkSort (_, x) = False

ultraChecker :: [String] -> [String] -> Bool
ultraChecker x y = checkInt x && checkList y

excuteALL :: [String] -> ([Int], [Int]) -> Bool
excuteALL instruc value = checkSort (swap instruc value) 

mainScript :: [String] -> ([Int], [Int]) -> IO ()
mainScript instruc value = do
    result <- case (excuteALL instruc value) of
        True -> putStrLn "OK"
        False -> putStrLn "KO"
    return ()

main :: IO ()
main = do
    line <- getLine
    args <- getArgs
    let checker = ultraChecker args (getList line)
    result <- case checker of
        True -> mainScript (getList line) (map (read::String -> Int) args, [])
        False -> exitWith (ExitFailure 84)
    
    return ()
