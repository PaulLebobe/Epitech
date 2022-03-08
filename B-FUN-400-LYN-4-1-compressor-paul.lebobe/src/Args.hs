module Args (
    handleArgument
    ,checkArgument
    ,errorManage
) where

import System.Exit ( ExitCode(ExitFailure), exitWith )
import Control.Monad ()


handleArgument :: [String] -> (Int, Float, String) -> (Int, Float, String)
handleArgument [] (a, b, c) = (a, b, c)
handleArgument ("-n":x:xs) (a, b, c) = handleArgument xs (read x :: Int, b, c)
handleArgument ("-l":x:xs) (a, b, c) = handleArgument xs (a, read x :: Float, c)
handleArgument ("-f":x:xs) (a, b, c) = handleArgument xs (a, b, x)
handleArgument _ (a, b, c) = (a, b, c)

checkArgument :: (Int, Float, String) -> Bool
checkArgument (-1, _, _) = False
checkArgument (_, -1, _) = False
checkArgument (_, _, "no") = False
checkArgument _ = True

errorManage :: Bool -> IO()
errorManage False = exitWith (ExitFailure 84)
errorManage True = return ()