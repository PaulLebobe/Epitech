module Cluster (
    nbCluster,
    createCluster
) where

import System.Random

nbCluster :: Int -> [(Int, Int, Int)] -> IO [(Int, Int, Int)]
nbCluster 0 z = return z
nbCluster a z = do
    x <- createCluster
    nbCluster (a - 1) (x : z)

createCluster :: IO (Int, Int, Int)
createCluster = do
    a <- randomRIO (0, 255)
    b <- randomRIO (0, 255)
    c <- randomRIO (0, 255)
    return (a, b, c)

calculConv :: (Int, Int, Int) -> (Int, Int, Int) -> Int
calculConv ([], [], []) ([], [], []) = []
calculConv (a, b, c) [] = []
calculConv [] (a2, b2, c2) = []
calculConv (a, b, c) (a2, b2, c2) = sqrt((a − a2) * (a − a2) + (b − b2) * (b − b2) + (c − c2) * (c − c2))

calculCluster :: [(Int, Int, Int)] -> (Int, Int, Int) -> Int -> Int
calculCluster [(a, b, c):xs] (a2, c2, b2) x = if calculConv((a, b, c) (a2, c2, b2)) < calculConv (xs (a2, b2, c2))
    then return x
    else return (x + 1)