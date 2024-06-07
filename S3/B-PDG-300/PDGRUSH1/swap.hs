{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- swap
-}

module Swap where
import Command

sSwap :: [Char] -> ([Int], [Int]) -> ([Int], [Int])
sSwap x int = case x of
    "a" -> sa int
    "b" -> sb int
    "c" -> sc int

pSwap :: [Char] -> ([Int], [Int]) -> ([Int], [Int])
pSwap x int = case x of
    "a" -> pa int
    "b" -> pb int

rSwap :: [Char] -> ([Int], [Int]) -> ([Int], [Int])
rSwap x int = case x of
    "a" -> ra int
    "b" -> rb int
    "r" -> rr int
    "ra" -> rra int
    "rb" -> rrb int
    "rr" -> rrr int

swap :: [String] -> ([Int], [Int]) -> ([Int], [Int])
swap [] x = x
swap ((y:ys):xs) int = case y of
    's' -> swap xs (sSwap (ys) int)
    'p' -> swap xs (pSwap (ys) int)
    'r' -> swap xs (rSwap (ys) int)
