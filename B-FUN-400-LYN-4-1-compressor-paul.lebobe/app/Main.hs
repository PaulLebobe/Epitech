module Main where

import System.Environment ( getArgs )
import System.Exit ( ExitCode(ExitSuccess, ExitFailure), exitWith )
import Args
import File
import Cluster

third :: (Int, Float, String) -> String
third (a, b, c)  = c

main :: IO ()
main = do
    argv <- getArgs
    let args = handleArgument argv (-1, -1, "no")
    errorManage(checkArgument args)
    c <- readFile (third args)
    print ((separate (replaceString (lines c))))
    print args
    -- cluster <- nbCluster args[0] []
    return ()