-- {-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
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

-- Author: Michael Zarkov

import Data.List (find)

-- Task 1. 

type Kid = String
type Dog = String

-- >>> length $ allPermutations [1,2,3]
-- 6
-- >>> allPermutations [1,2,3]
-- [[1,2,3],[1,3,2],[2,1,3],[3,1,2],[2,3,1],[3,2,1]]

allPermutations :: [a] -> [[a]]
allPermutations [] = [[]]
allPermutations (h:t) = foldr (++) [] $ map (\n -> put h n p) [0..length t]
  where
    p = allPermutations t
    put :: a -> Int -> [[a]] -> [[a]] 
    put a n aas = map (\as -> take n as ++ [a] ++ drop n as) aas

lks :: Kid -> [Dog]
lks "Ivan" = ["Sharo","Sivcho"]
lks "Maria" = ["Sivcho"]
lks "Alex" = ["Murjo"]
lks _ = []

-- >>> matchDogs ["Ivan","Maria","Alex"] ["Sharo","Sivcho","Murjo"] lks
matchDogs :: [Kid] -> [Dog] -> (Kid -> [Dog]) -> [(Kid, Dog)]
matchDogs ks ds likes = 
  case find (\l -> all (\(k,d) -> d `elem` likes k) l) zipped of
    Just result -> result
    _ -> []  
  where
    p = allPermutations ds
    zipped = map (zip ks) p


-- Task 2.

type Qst = String
type Ans = String

chatFOS5 :: Int -> (Qst -> Qst -> Int) -> (Qst -> Ans -> Ans) -> [Qst] -> [Ans]
chatFOS5 n dist comb qs = getFirstNAns [] ++ answerStream qs (getFirstNAns []) 
  where 
    getFirstNAns :: [Ans] -> [Ans]
    getFirstNAns [] = getFirstNAns [head qs]
    getFirstNAns as =
      if l == n 
        then as
        else getFirstNAns $ as ++ [newAns]
      where
        l = length as  
        newAns :: Ans
        newAns = 
          let newQst = qs !! l
              distances = map (dist newQst) $ take l qs
              minDist = minimum distances
              pairs = zip distances as in
            case find (\(d,_) -> d == minDist) pairs of
              Just (_,ans) -> comb newQst ans
              _ -> "Logic error task 2!" 

    -- 'n' answers are already generated.
    answerStream :: [Qst] -> [Ans] -> [Ans]
    answerStream qs as =
      let newAns = getNewAns qs as in
        newAns : answerStream (drop 1 qs) (drop 1 as ++ [newAns]) 
    
    getNewAns :: [Qst] -> [Ans] -> Ans
    getNewAns qs as = 
      let [newQst] = drop n $ take (n+1) qs 
          ans = shortestDistanceAns qs as in 
        comb newQst ans 
      where
        shortestDistanceAns :: [Qst] -> [Ans] -> Ans
        shortestDistanceAns qs as =
          let newQst = qs !! n
              distances = map (dist newQst) $ take n qs
              minDist = minimum distances
              pairs = zip distances (take n as) in
            case find (\(d,_) -> d == minDist) pairs of 
              Just (_,ans) -> ans
              _ -> error "Logic error in task 2!"


-- Task 3. 

type Piece = (String, String, Int)

removeDuplicates :: Eq a => [a] -> [a] 
removeDuplicates [] = []
removeDuplicates (h:t) =
  if h `elem` t
    then removeDuplicates t
    else h : removeDuplicates t

items :: [Piece]
items = [("A1","A",1920), ("A2","A",1930), ("B1","B",1925), ("B2","B",1935), ("C1","C",1930)]

-- >>> maxYear items
-- 1930
maxYear :: [Piece] -> Int 
maxYear ps = 
  case find (\y -> maxCats == categoriesInYear y) ys of
    Just resultYear -> resultYear
    _ -> error "Error task 3!"
  where 
    ys = removeDuplicates $ map (\(_,_,y) -> y) ps
    maxCats = maximum $ map categoriesInYear ys

    categoriesInYear :: Int -> Int
    categoriesInYear year = 
      length $
      removeDuplicates $
      map (\(_,c,_) -> c) $
      filter (\(_,_,y) -> y == year) ps

-- >>> middleItems items
-- ["A2","B1","C1"]
middleItems :: [Piece] -> [String]
middleItems ps = [ n | p@(n,_,_) <- ps, go p]
  where 
    cs = removeDuplicates $ map (\(_,c,_) -> c) ps
    
    go :: Piece -> Bool
    go p = any (checkCat p) cs

    checkCat :: Piece -> String -> Bool 
    checkCat (_,c,y) cat = 
      c /= cat && 
      let diffCatPs = filter (\(_,c1,_) -> c1 == cat) ps
          older = filter (\(_,_,y1) -> y1 < y) diffCatPs
          newer = filter (\(_,_,y1) -> y < y1) diffCatPs in
        length older == length newer
