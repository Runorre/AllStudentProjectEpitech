{-
-- EPITECH PROJECT, 2024
-- Day01
-- File description:
-- Pool Tek 2 Day 1
-}

mySucc :: Int -> Int
mySucc nb = nb + 1

myIsNeg ::  Int -> Bool
myIsNeg n | n >= 0 = False
            | n < 0 = True

myAbs :: Int -> Int
myAbs n | n >= 0 = n
        | n < 0 = n * (-1)

myMin :: Int -> Int -> Int
myMin n1 n2 | n1 <= n2 = n1
            | n1 > n2 = n2

myMax :: Int -> Int -> Int
myMax n1 n2 | n1 >= n2 = n1
            | n1 < n2 = n2

myTuple :: a -> b -> (a , b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c = (a, b, c)

myFst :: (a , b) -> a
myFst (a, b) = a

mySnd :: (a , b) -> b
mySnd (a , b) = b

mySwap :: (a , b) -> (b , a)
mySwap (a , b) = (b , a)

myHead :: [a] -> a
myHead [] = error "myHead: empty list"
myHead (x:_) = x


myTail :: [a] -> [a]
myTail [] = error "myTail: empty list"
myTail (_:x) = x

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [] _ = error "myNth: empty list"
myNth (x:xs) 0 = x
myNth (x:xs) b 
    | b < 0 =  error "myNth: negative"
    | b /= 0 = myNth xs (b - 1)

myTake :: Int -> [a] -> [a]
myTake y _ | y <= 0 = []
myTake _ [] = []
myTake 1 (x:xs) = [x]
myTake y (x:xs) = x:myTake (y - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop y x | y <= 0 = x
myDrop _ [] = []
myDrop 1 (x:xs) = xs
myDrop y (x:xs) = myDrop (y - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] (x:xs) = x:myAppend [] xs
myAppend (x:xs) y = x:myAppend xs y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "myInit: empty list"
myInit x | myLength x == 1 = []
myInit (x:xs) = x : myInit xs

myLast :: [a] -> a
myLast [] = error "myInit: empty list"
myLast x | myLength x == 1 = myHead x
myLast (x:xs) = myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x,y):myZip xs ys

myUnzip :: [(a, b)] -> ([a] , [b])
myUnzip [] = ([], [])
myUnzip ((x, y): xs) = (x:myFst (myUnzip xs), y:mySnd (myUnzip xs))

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f (x:xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (x:xs) | f x = x : myFilter f xs 
                | f x == False = myFilter f xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ x [] = x
myFoldl f x (y:ys) = myFoldl f (f x y) ys

myFoldr :: (b -> a -> b) -> b -> [a] -> b
myFoldr _ x [] = x
myFoldr f x y = myFoldl f (f x (myLast y)) (myReverse (myTail (myReverse y)))

myReversefilter :: (a -> Bool) -> [a] -> [a]
myReversefilter _ [] = []
myReversefilter f (x:xs) | f x = myReversefilter f xs 
                | f x == False = x : myReversefilter f xs

myPartition :: (a -> Bool) -> [a] -> ([a] , [a])
myPartition f x = (myFilter f x, myReversefilter f x)

