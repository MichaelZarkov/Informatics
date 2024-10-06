-- cover all cases!
{-# OPTIONS_GHC -fwarn-incomplete-patterns #-}
-- warn about incomplete patterns v2
{-# OPTIONS_GHC -fwarn-incomplete-uni-patterns #-}
-- write all your toplevel signatures!
{-# OPTIONS_GHC -fwarn-missing-signatures #-}
-- use different names!
{-# OPTIONS_GHC -fwarn-name-shadowing #-}
-- use all your pattern matches!
{-# OPTIONS_GHC -fwarn-unused-matches #-}


import Data.List (find)

-- These are my solutions to the variant A of the example exam.

-- Task 1, variant A.
-- Example: : somos 4 -> 1 1 1 1 2 3 7 23 59 314 1529 ...
nOnes :: Int -> [Double] 
nOnes n
  | n <= 0 = error "Error! Number must be an integer greater than zero!"
  | otherwise = [ 1 | _ <- [1..n]]

somos :: Int -> [Double] 
somos k = nOnes k ++ [ getSum (symmetricPairs i) / (somos k !! (i-k)) | i <- [k..] ]
  where 
    symmetricPairs :: Int -> [(Double,Double)]
    symmetricPairs i =
      let interval = drop (i-(k-1)) $ take i $ somos k
          k2 = div k 2 in 
        zip (take k2 interval) $ reverse $ drop (k2-1) interval

    getSum :: [(Double,Double)] -> Double
    getSum = foldr (\(a,b) res -> a*b + res) 0


-- Task 2, variant A. 
-- Упътване: автомат с n състояния разпознава всички възможни думи точно тогава, когато разпознава всички възможни думи с дължина до n.
-- Examples: 
--   ({0,1,2}, 0, {(0,A,1),(1,B,1),(1,A,2),(2,A,2),(2,B,1)}, {0,1,2}) -> doesn't recognize the word "b".
--   ({0,1,2}, 0, {(0,A,1),(1,B,1),(1,A,2),(2,A,2),(2,B,1),(0,B,1)}, {0,1,2}) -> recognizes all words.
--   ({0}, 0, {}, {}) -> doesn't recognize any word.
-- >>> rejectedWord ([0,1,2], 0, [(0,A,1),(1,B,1),(1,A,2),(2,A,2),(2,B,1)], [0,1,2])
-- Just "b"
-- >>> rejectedWord ([0,1,2], 0, [(0,A,1),(1,B,1),(1,A,2),(2,A,2),(2,B,1),(0,B,1)], [0,1,2])
-- Nothing
-- >>> rejectedWord ([0], 0, [], [])
-- Just ""

data Alphabet = A | B deriving (Show, Read, Eq)
type Automata = ([Int],Int,[(Int,Alphabet,Int)],[Int])

-- Returns all words with length up to N with letters from alphabet. 
wordsToN :: Int -> [[Alphabet]]
wordsToN n
  | n > 0 =
    let r = wordsToN $ n-1 in 
      r ++ map ([A] ++) r ++ map ([B] ++) r
  | n == 0 = [[]]  -- The empty word is the only one with length 0.
  | otherwise = error "Error! A word cannot have negative length!"

-- Връща 'Just word', ако намери дума, която не се разпознава от автомата. 
-- Връща 'Nothing', ако автоматът разпознава всички думи.
-- Очаква коректно зададен входен автомат.
-- Забележка: автомат с n състояния разпознава всички възможни думи точно тогава, когато разпознава всички
--            възможни думи с дължина до n. Функцията прави точно това - проверява всички думи с дължина по-малка от n.
rejectedWord :: Automata -> Maybe String
rejectedWord (q,start,t,f) =
  case find (\w -> not $ isRecognized w start) $ wordsToN $ length q of 
    Just word -> Just $ toString word
    _ -> Nothing
  where 
    -- Takes a word and a starting state.
    -- Returns true if the word ends in a final state.
    isRecognized :: [Alphabet] -> Int -> Bool 
    isRecognized [] state = state `elem` f
    isRecognized (c:cs) state =
      let transitions = filter (\(q1,letter,_) -> state == q1 && c == letter) t in
        not (null transitions) &&  -- If there is no transition to another state then the word is not recognized.
        any (\(_,_,q2) -> isRecognized cs q2) transitions

toString :: [Alphabet] -> String 
toString = foldr op []
  where 
    op :: Alphabet -> String -> String
    op A r = "a" ++ r
    op B r = "b" ++ r


-- Task 3, variant A.
-- Examples:
--   [(+),(-),(*)] [1,2,0,3,-1] -> -7 == (1 – (2 * (0 + (3 - (-1)))))
--   [(+),(*)] [-1,2,3,-2,4] -> -11 == (-1 + (2 * (3 + (-2 * 4))))
-- >>> findMin [(+),(-),(*)] [1,2,0,3,-1]
-- -7.0
-- >>> findMin [(+),(*)] [-1,2,3,-2,4]
-- -11.0

-- Makes a finite list infinite.
series :: [a] -> [a]
series l = l ++ series l 

type Fun = Double -> Double -> Double
findMin :: [Fun] -> [Double] -> Double
findMin fs xs =
  minimum $ [ go (drop i s) xs | i <- [0..m-1]]
  where 
    m = length fs
    s = series fs
    -- This function should work faster if the error check is removed.
    go :: [Fun] -> [Double] -> Double
    go _ [] = error "Error! Expected list with at least two numbers!"
    go _ [_] = error "Error! Expected list with at least two numbers!"
    go [] _ = error "Error! Expected an infinite list of functions!"
    go (h:_) [n1,n2] = h n1 n2
    go (h:t) (n:ns) = h n $ go t ns


-- Task 4, variant A.
-- Examples:
--   [("Angel",14,15),("Andrei",8,10),("Atanas",10,3),("Georgi",6,4)] -> [("Angel",22),("Georgi",6),("Andrei",12),("Atanas",4)]
-- Note: In the pdf file with the tasks, the example for this task is incorrect!
--       The example in this file should be correct.
-- >>> finalScores [("Angel",14,15),("Andrei",8,10),("Atanas",10,3),("Georgi",6,4)]
-- [("Angel",22),("Georgi",6),("Andrei",12),("Atanas",4)]

quickSort :: (a -> a -> Bool) -> [a] -> [a]
quickSort _ [] = []
quickSort ltOrEq (h:t) =
  quickSort ltOrEq [ x | x <- t, x `ltOrEq` h ] ++ [h] ++ quickSort ltOrEq [ x | x <- t, not $ x `ltOrEq` h ]

finalScores :: [(String,Int,Int)] -> [(String,Int)]
finalScores l = zipWith (\(name,_,score) (_,diff,_) -> (name, score + diff)) sorted $ reverse sorted
  where 
    lessThanOrEq :: (String,Int,Int) -> (String,Int,Int) -> Bool
    lessThanOrEq (_,difference1,_) (_,difference2,_) = difference1 <= difference2
    sorted = quickSort lessThanOrEq $
      map (\(name,prediction,score) -> (name, abs $ score - prediction, score)) l
