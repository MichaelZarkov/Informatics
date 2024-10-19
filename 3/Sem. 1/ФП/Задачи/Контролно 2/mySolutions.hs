
main :: IO()
main = do
    print $ listsWithSuffix [[1,2,3],[2,3,4],[3,4,5]] [[3],[3,5],[3,4]] == 2
    print $ maxListsWithSuffix [[1,2],[3,4]] [[[2]],[[2],[4]]] == [[2],[4]]

-- Task 1.
isSuffix :: [Int] -> [Int] -> Bool
isSuffix _ [] = True 
isSuffix [] _ = False
isSuffix (x:xs) s = (x:xs) == s || isSuffix xs s

-- Returns how many lists have suffixes.
listsWithSuffix :: [[Int]] -> [[Int]] -> Int
listsWithSuffix [] _ = 0
listsWithSuffix (ns:nss) mss = 
    if any (isSuffix ns) mss
        then 1 + listsWithSuffix nss mss 
        else listsWithSuffix nss mss

maxListsWithSuffix :: [[Int]] -> [[[Int]]] -> [[Int]]
maxListsWithSuffix _ [] = error "Cannot find max of empty list!"
maxListsWithSuffix l (s:ls) = helper ls s (listsWithSuffix l s)
    where 
        helper :: [[[Int]]] -> [[Int]] -> Int -> [[Int]]
        helper [] r _ = r 
        helper (s:ls) res max = 
            if listsWithSuffix l s > max 
                then helper ls s (listsWithSuffix l s)
                else helper ls res max

-- Task 2. 
member :: Eq a => [a] -> a -> Bool
member [] _ = False
member (m:ms) n  = n == m || member ms n

candidateNames :: [[String]] -> [String] -> [String]
candidateNames [] res = res 
candidateNames (v:vs) res = candidateNames vs (res ++ filter (not . member res) v)

-- Returns number of votes for single candidate.
candidateCountVotes :: String -> [[String]] -> Int
candidateCountVotes c = foldr ((+) . (\(h:t) -> if member t c then 1 else 0)) 0

countVotes :: [[String]] -> [(String, Int)] 
countVotes vs = map (\name -> (name, candidateCountVotes name vs)) (candidateNames vs [])

-- Task 3.
pairs :: [(Int, Int)]
pairs = [ (x, y) | z <- [2..], x <- [1..z-1], y <- [z - x]]

isRight :: (Int, Int) -> Bool
isRight (x, y) = x < y 

rightPairs :: [(Int, Int)] 
rightPairs = filter isRight pairs

canceledPairs :: [(Int, Int)] 
canceledPairs = undefined

fractionalPairs :: [((Int, Int), (Int,Int))]
fractionalPairs = undefined