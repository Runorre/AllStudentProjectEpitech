{-
-- EPITECH PROJECT, 2024
-- HackatonWeek
-- File description:
-- HackatonWeek
-}

module Main where

import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

import Move

handleKeys :: Event -> TronGame -> TronGame
handleKeys (EventKey (Char 'i') _ _ _) game
  | menu game == Menu = game { menu = Keys }
  | menu game == Keys = game { menu = Menu }
handleKeys (EventKey (Char 'z') _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | snd (p1Dir game) == -150 = game
  | otherwise                = game { p1NextDir = (0, 150) }
handleKeys (EventKey (Char 's') _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | snd (p1Dir game) == 150  = game
  | otherwise                = game { p1NextDir = (0, -150) }
handleKeys (EventKey (Char 'q') _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | fst (p1Dir game) == 150  = game
  | otherwise                = game { p1NextDir = (-150, 0) }
handleKeys (EventKey (Char 'd') _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | fst (p1Dir game) == -150 = game
  | otherwise                = game { p1NextDir = (150, 0) }
handleKeys (EventKey (SpecialKey KeyUp) _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | snd (p2Dir game) == -150 = game
  | otherwise                = game { p2NextDir = (0, 150) }
handleKeys (EventKey (SpecialKey KeyDown) _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | snd (p2Dir game) == 150  = game
  | otherwise                = game { p2NextDir = (0, -150) }
handleKeys (EventKey (SpecialKey KeyLeft) _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | fst (p2Dir game) == 150  = game
  | otherwise                = game { p2NextDir = (-150, 0) }
handleKeys (EventKey (SpecialKey KeyRight) _ _ _) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | fst (p2Dir game) == -150 = game
  | otherwise                = game { p2NextDir = (150, 0) }
handleKeys (EventKey {}) game
  | not (isGameStarted game) = game { isGameStarted = True }
  | otherwise                = game
handleKeys _ game = game

positionToPic :: (Float, Float) -> Color -> Picture
positionToPic (x, y) c = translate x y (color c (rectangleSolid 10 10))

positionsToPic :: [(Float, Float)] -> Color -> Picture
positionsToPic [] _ = blank
positionsToPic (p:ps) c = pictures [positionToPic p c, positionsToPic ps c]

wallX :: Float -> Picture
wallX y = translate 0 y (color green (rectangleSolid 1420 10))

wallY :: Float -> Picture
wallY x = translate x 0 (color green (rectangleSolid 10 810))

bikeTranslateRotate :: (Float, Float) -> Float -> Float -> Picture -> Picture
bikeTranslateRotate pos (-150) _ bike = uncurry translate pos (rotate 180 bike)
bikeTranslateRotate pos _ 150 bike    = uncurry translate pos (rotate 270 bike)
bikeTranslateRotate pos _ (-150) bike = uncurry translate pos (rotate 90 bike)
bikeTranslateRotate pos _ _ bike      = uncurry translate pos bike

scoreTranslate :: Color -> Float -> Int -> Picture
scoreTranslate col pos score = coloredPicture
  where
    scoreText = text (show score)
    scaledText = scale 0.5 0.5 scoreText
    translatedText = translate pos 420 scaledText
    coloredPicture = color col translatedText

getPlayers :: Picture -> Picture -> TronGame -> (Picture, Picture)
getPlayers redBike blueBike game = (p1, p2)
  where
    p1 = uncurry (bikeTranslateRotate (p1Pos game)) (p1Dir game) redBike
    p2 = uncurry (bikeTranslateRotate (p2Pos game)) (p2Dir game) blueBike

getTrails :: TronGame -> (Picture, Picture)
getTrails game = (trail1, trail2)
  where
    trail1 = positionsToPic (p1Trail game) red
    trail2 = positionsToPic (p2Trail game) blue

getLogos :: Picture -> Picture -> Picture -> (Picture, Picture, Picture)
getLogos l1 l2 l3 = (l1', l2', l3')
  where
    l1' = translate (-420) 435 l1
    l2' = translate 445 440 l2
    l3' = translate (-0) 445 l3

getScore :: TronGame -> (Picture, Picture)
getScore game = (score1, score2)
  where
    score1 = scoreTranslate red (-300) (p1Score game)
    score2 = scoreTranslate blue 300 (p2Score game)

getTek2 :: Picture -> Picture -> (Picture, Picture)
getTek2 sonny celestin = (sonny', celestin')
  where
    sonny' = translate (-850) (-50) sonny
    celestin' = translate 850 (-50) celestin

getBg :: (Picture, Picture)
getBg = (outline, blackbg)
  where
    outline = pictures [wallX 400, wallX (-400), wallY 710, wallY (-710)]
    blackbg = color black (rectangleSolid 1420 810)

render :: [Picture] -> TronGame -> Picture
render [bg, sonny, celestin, menuPic, keys, redBike, blueBike, l1, l2, ti] game = case gameState game of
  Playing
    | isGameStarted game -> drawPictures [trail1, trail2, p1, p2]
    | menu game == Keys -> keys
    | otherwise -> menuPic
  GameOver t
    | isGameStarted game && even (round (t * 10) :: Int) -> drawPictures [trail1, trail2, p1, p2]
    | winner game == P1 -> drawPictures [trail1, p1]
    | winner game == P2 -> drawPictures [trail2, p2]
    | menu game == Keys -> keys
    | otherwise -> menuPic
  where
    (p1, p2) = getPlayers redBike blueBike game
    (trail1, trail2) = getTrails game
    (l1', l2', t') = getLogos l1 l2 ti
    (outline, blackbg) = getBg
    (score1, score2) = getScore game
    (sonny', celestin') = getTek2 sonny celestin
    drawPictures extraPics = pictures ([bg, sonny', celestin', blackbg, outline, score1, score2, l1', l2', t'] ++ extraPics)
render _ _ = error "Invalid number of pictures"

window :: Display
window = InWindow "Don't Cross The Line" (1920, 1080) (0, 0)

update :: Float -> TronGame -> TronGame
update seconds game = case gameState game of
  Playing | isGameStarted game -> moveP2 seconds (moveP1 seconds game)
          | otherwise -> game
  GameOver t | t < 1 -> game { gameState = GameOver (t + seconds) }
             | winner game == P1 -> initialState {
                 p1Score = p1Score game + 1, p2Score = p2Score game,
                 isGameStarted = True }
             | otherwise -> initialState {
                p1Score = p1Score game, p2Score = p2Score game + 1,
                isGameStarted = True }

loadAssets :: IO [Picture]
loadAssets = mapM loadBMP [
    "app/assets/bg.bmp",
    "app/assets/sonny.bmp", "app/assets/celestin.bmp",
    "app/assets/menu.bmp", "app/assets/keys.bmp",
    "app/assets/redbike.bmp", "app/assets/bluebike.bmp",
    "app/assets/Player1.bmp", "app/assets/Player2.bmp",
    "app/assets/title.bmp"
  ]

main :: IO ()
main = do
  assets <- loadAssets
  let renderFunc = render assets
  play window black 60 initialState renderFunc handleKeys update
