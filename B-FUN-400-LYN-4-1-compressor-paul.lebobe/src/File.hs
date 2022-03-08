{-# OPTIONS_GHC -Wno-deferred-type-errors #-}
module File (
    replaceChar
    ,replaceString
    ,separate
    ,createTuple
) where
import Data.List
replaceChar :: String -> String
replaceChar [] = []
replaceChar ('(':xs) = '\n' : replaceChar xs
replaceChar (')':xs) = '\n' : replaceChar xs
replaceChar (',':xs) = '\n' : replaceChar xs
replaceChar (' ':xs) = '\n' : replaceChar xs
replaceChar (x:xs) = x : replaceChar xs

replaceString :: [String] -> [String]
replaceString = map replaceChar

separate :: [String] -> [[String]]
separete [] = []
separate (x:xs) = filter (not . null) (lines x) : separate xs
separate _ = []

createTuple :: [[String]] -> [((Int, Int), (Int, Int, Int))]
createTuple [] = []
createTuple ([a, b, c, d, e]:xs) = ((read a :: Int, read b :: Int) , (read c :: Int, read d ::Int, read e ::Int)) : createTuple xs