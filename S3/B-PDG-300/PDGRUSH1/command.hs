{-
-- EPITECH PROJECT, 2024
-- Rush 1
-- File description:
-- command
-}

module Command where

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = [];
myAppend [] (x:xs) =  x:myAppend [] xs
myAppend (x:xs) [] = x:myAppend xs []
myAppend (x:xs) y = x:myAppend xs y

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myTake :: Int -> [a] -> [a]
myTake nb _ | nb <= 0 = []
myTake _ [] = []
myTake 1 (x:xs) = [x]
myTake nb (x:xs) = x:myTake (nb-1) xs

myFst :: (a, b) -> a
myFst (a,b) = a

mySnd :: (a, b) -> b
mySnd (a,b) = b

sa :: ([a], [a]) -> ([a], [a])
sa ([], b) = ([], b)
sa (a, b) | length a < 2 = (a, b)
sa ((x:y:xs), b) = ((y:x:xs), b)

sb :: ([a], [a]) -> ([a], [a])
sb (a, []) = (a, [])
sb (a, b) | length b < 2 = (a, b)
sb (a, (y:z:ys)) = (a, (z:y:ys))

sc :: ([a], [a]) -> ([a], [a])
sc x = (myFst(sa x), mySnd(sb x))

pa :: ([a], [a]) -> ([a], [a])
pa (a, []) = (a, [])
pa (a, (y:ys)) = ((y:a), ys)

pb :: ([a], [a]) -> ([a], [a])
pb ([], a) = ([], a)
pb ((x:xs), b) = (xs, (x:b))

ra :: ([a], [a]) -> ([a], [a])
ra ((x:xs), y) = (myAppend xs [x], y)

rb :: ([a], [a]) -> ([a], [a])
rb (x, (y:ys)) = (x, myAppend ys [y])

rr :: ([a], [a]) -> ([a], [a])
rr x = (myFst(ra x), mySnd(rb x))

rra :: ([a], [a]) -> ([a], [a])
rra (x, y) = ((last x : (myTake ((myLength x)-1) x)), y)

rrb :: ([a], [a]) -> ([a], [a])
rrb (x, y) = (x, (last y : (myTake ((myLength y)-1) y)))

rrr :: ([a], [a]) -> ([a], [a])
rrr x = (myFst(rra x), mySnd(rrb x))
