module Main where

import Lib ()
import Data.Maybe ( fromJust )
import Data.List ()
import System.Environment ( getArgs )
import Control.Applicative ( Alternative((<|>), empty, some) )
import GHC.IO.Buffer (isEmptyBuffer)
import GHC.Stack.Types (CallStack(EmptyCallStack))
import Data.Bifunctor ( Bifunctor(first) )
import System.IO ()
import Data.Char (digitToInt, isDigit)
import Data.String (IsString(fromString))
import GHC.Exts (IsString(fromString))
import Text.Printf ( printf )
import System.Exit ( ExitCode(ExitFailure), exitWith )
import Debug.Trace ()

-- type Parser a = String -> Maybe (a, String)

data Parser a = Parser {
runParser :: String -> Maybe (a, String)
}

data Expr = Add Expr Expr
        | Sub Expr Expr
        | Mul Expr Expr
        | Div Expr Expr
        | Pow Expr Expr
        | Noth Float

instance Functor Parser where
    fmap fct (Parser p) = Parser $ \s -> case p s of
        Nothing -> Nothing
        Just (c, s') -> Just (fct c, s')

instance Applicative Parser where
    pure x = Parser $ \s -> Just (x, s)
    Parser p1 <*> p2 = Parser $ \s -> case p1 s of
        Just (f, s') -> case runParser p2 s' of
            Just (a, s'') -> Just (f a, s'')
            Nothing -> Nothing
        Nothing -> Nothing

instance Alternative Parser where
    empty = Parser $ const Nothing
    Parser pa <|> pb = Parser $ \str -> pa str <|> runParser pb str

parseChar :: Char -> Parser Char
parseChar x = Parser $ \string -> case string of
    [] -> Nothing
    _ -> if x == head string then Just (x, tail string)
    else Nothing

parseAnyChar :: String -> Parser Char
parseAnyChar [] = Parser $ const Nothing
parseAnyChar (x:xs) = Parser $ \string -> case string of
    [] -> Nothing
    _ -> if x == head string then Just (x, tail string)
    else runParser (parseAnyChar xs) string

parseOr :: Parser a -> Parser a -> Parser a
parseOr x y = Parser $ \str -> case runParser x str of
    Nothing -> runParser y str
    Just (c, str') -> runParser x str

parseAnd :: Parser a -> Parser b -> Parser (a, b)
parseAnd left right = Parser $ \str -> case runParser left str of
    Nothing -> Nothing
    Just (c, str') -> case runParser right str' of
        Nothing -> Nothing
        Just (c', str'') -> Just ((c, c'), str'')

parseAndWith :: (a -> b -> c) -> Parser a -> Parser b -> Parser c
parseAndWith f x y = Parser $ \str -> case (runParser $ parseAnd x y) str of
    Nothing -> Nothing
    Just ((c,c'), str') -> Just (f c c' , str')

parseMany :: Parser a -> Parser [a]
parseMany x = Parser $ \str -> case runParser x str of
    Nothing -> Just (empty, str)
    Just (c,str') -> Just (Data.Bifunctor.first (c :) (fromJust ((runParser $ parseMany x) str')))

parseSome :: Parser a -> Parser [a]
parseSome x = Parser $ \str -> case runParser x str of
    Nothing -> Nothing
    Just (c, str') -> Just (Data.Bifunctor.first (c :) (fromJust ((runParser $ parseMany x) str')))

ope :: Expr -> Float
ope e = case e of
    Add a b -> ope a + ope b
    Sub a b -> ope a - ope b
    Mul a b -> ope a * ope b
    Div a b -> ope a / ope b
    Pow a b -> ope a ** ope b
    Noth n -> n

parse :: Parser a -> String -> Maybe a
parse (Parser a) s = case a s of
    Just i -> Just (fst i)
    _ -> Nothing

parseString :: String -> Parser String
parseString = traverse parseChar

checkParser :: (a -> Bool) -> Parser a -> Parser a
checkParser pred (Parser p) = Parser $ \input -> do
    (parsed, input') <- p input
    if pred parsed
        then Just (parsed, input')
        else Nothing

makeFloat :: [Parser String]
makeFloat = [parseString "-" <|> pure "", parseNumberString,
    ((++) <$> parseString "." <*> parseNumberString) <|> pure ""]

parseNumberString :: Parser String
parseNumberString = some $ parseAnyChar "0123456789"

sign :: Parser Expr
sign = add_sub
    where
        add_sub = binOp Add '+' parens sign <|> binOp Sub '-' parens sign <|> mul_div
        mul_div = binOp Mul '*' parens sign <|> binOp Div '/' parens sign <|> pow
        pow = binOp Pow '^' parens sign <|> parens
        parens = parseChar '(' *> sign <* parseChar ')' <|> noth
        noth = Noth . read <$> (concat <$> sequenceA makeFloat)
        binOp c o p p2 = c <$> (p <* parseChar o) <*> p2


strip :: String -> String -> String
strip = filter . flip notElem

main :: IO ()
main = do
    x <- getArgs
    let str = strip " \t" (head x)
    if length x == 1 && not (null str) then case fmap ope $ parse sign $ concat $ words str of
        Just res -> printf "%.2f\n" res
        Nothing -> print "Error"
    else
        exitWith $ ExitFailure 84