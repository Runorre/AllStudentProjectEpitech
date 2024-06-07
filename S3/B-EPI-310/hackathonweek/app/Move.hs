{-
-- EPITECH PROJECT, 2024
-- HackatonWeek
-- File description:
-- HackatonWeek
-}

module Move where

data TronGameMenu = Menu | Keys deriving Eq

data TronGameState = Playing | GameOver Float

data TronGameWinner = P1 | P2 | None deriving Eq

data TronGame = Game {
  gameState :: TronGameState, isGameStarted :: Bool,
  menu :: TronGameMenu,
  p1Dir :: (Float, Float), p2Dir :: (Float, Float),
  p1NextDir :: (Float, Float), p2NextDir :: (Float, Float),
  p1Pos :: (Float, Float), p2Pos :: (Float, Float),
  p1Score :: Int, p2Score :: Int,
  p1Trail :: [(Float, Float)], p2Trail :: [(Float, Float)],
  winner :: TronGameWinner
}

initialState :: TronGame
initialState = Game {
  gameState = Playing, isGameStarted = False,
  menu = Menu,
  p1Dir = (150, 0), p2Dir = (-150, 0),
  p1NextDir = (150, 0), p2NextDir = (-150, 0),
  p1Pos = (-600, 0), p2Pos = (600, 0),
  p1Score = 0, p2Score = 0,
  p1Trail = [], p2Trail = [],
  winner = None
}

addToTrail1 :: [(Float, Float)] -> (Float, Float) -> [(Float, Float)]
addToTrail1 [] (x, y) = [(x, y)]
addToTrail1 ps (x, y) | length ps > 1250 = (x, y) : init ps
                      | otherwise        = (x, y) : ps

addToTrail2 :: [(Float, Float)] -> (Float, Float) -> [(Float, Float)]
addToTrail2 [] (x, y) = [(x, y)]
addToTrail2 ps (x, y) | length ps > 1250 = (x, y) : init ps
                      | otherwise        = (x, y) : ps

isMultipleOf10 :: Int -> Int -> Bool
isMultipleOf10 x y = x `mod` 10 == 0 && y `mod` 10 == 0

gameOverP1 :: TronGame -> TronGame
gameOverP1 game = game {
  gameState = GameOver 0,
  p1Score = p1Score game,
  p2Score = p2Score game,
  winner = P1
}

gameOverP2 :: TronGame -> TronGame
gameOverP2 game = game {
  gameState = GameOver 0,
  p1Score = p1Score game,
  p2Score = p2Score game,
  winner = P2
}

isGameOver :: Float -> Float -> TronGame -> Bool
isGameOver x' y' game | x' < -700 || x' > 700 || y' < -390 || y' > 390 = True
                      | (x', y') `elem` p2Trail game                   = True
                      | (x', y') `elem` p1Trail game                   = True
                      | otherwise                                      = False

moveP1 :: Float -> TronGame -> TronGame
moveP1 seconds game
  | isGameOver x' y' game = gameOverP2 game
  | otherwise = updateGameP1 x' y' game
  where
    (x, y) = p1Pos game
    (dx, dy) = p1Dir game
    xInt = round (x + dx * seconds) :: Int
    yInt = round (y + dy * seconds) :: Int
    x' = fromIntegral xInt :: Float
    y' = fromIntegral yInt :: Float

updateGameP1 :: Float -> Float -> TronGame -> TronGame
updateGameP1 x' y' game
  | isMultipleOf10 (round x' :: Int) (round y' :: Int) = game {
      p1Pos = (x', y'), p1Trail = p1Trail', p1Dir = p1NextDir game
    }
  | otherwise = game { 
      p1Pos = (x', y'), p1Trail = p1Trail', p1Dir = p1Dir game
    }
  where
    p1Trail' = addToTrail1 (p1Trail game) (x', y')

moveP2 :: Float -> TronGame -> TronGame
moveP2 seconds game
  | isGameOver x' y' game = gameOverP1 game
  | otherwise = updateGameP2 x' y' game
  where
    (x, y) = p2Pos game
    (dx, dy) = p2Dir game
    xInt = round (x + dx * seconds) :: Int
    yInt = round (y + dy * seconds) :: Int
    x' = fromIntegral xInt :: Float
    y' = fromIntegral yInt :: Float

updateGameP2 :: Float -> Float -> TronGame -> TronGame
updateGameP2 x' y' game
  | isMultipleOf10 (round x' :: Int) (round y' :: Int) = game { 
      p2Pos = (x', y'), p2Trail = p2Trail', p2Dir = p2NextDir game
    }
  | otherwise = game {
      p2Pos = (x', y'), p2Trail = p2Trail', p2Dir = p2Dir game
    }
  where
    p2Trail' = addToTrail2 (p2Trail game) (x', y')
