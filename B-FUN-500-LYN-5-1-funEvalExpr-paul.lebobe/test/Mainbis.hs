module Main where

import Lib ()
import System.IO ()
import System.Environment ( getArgs )
import Control.Applicative ( Alternative((<|>), empty, some) )

data Expr = Add Expr Expr
          | Sub Expr Expr
          | Mul Expr Expr
          | Div Expr Expr
          | Lit Integer

eval :: Expr -> Integer
eval e = case e of
  Add a b -> eval a + eval b
  Sub a b -> eval a - eval b
  Mul a b -> eval a * eval b
  Div a b -> eval a `div` eval b
  Lit n   -> n

-- Nouveau datatype nécessaire pour les instances
data Parser r = Parser {parse :: String -> Maybe (r, String)}

-- Instances
instance Functor Parser where
  fmap f (Parser p) = Parser $ \s -> case p s of
    Just (a, s') -> Just (f a, s')
    Nothing      -> Nothing

instance Applicative Parser where
  pure x = Parser $ \s -> Just (x, s)
  Parser p1 <*> pp2 = Parser $ \s -> case p1 s of
    Just (f, s') -> case parse pp2 s' of
      Just (a, s'') -> Just (f a, s'')
      Nothing       -> Nothing
    Nothing -> Nothing

instance Alternative Parser where
  empty = Parser $ const Nothing
  (Parser p1) <|> pp2 = Parser $ \s -> p1 s <|> parse pp2 s

-- Le reste est identique
runParser :: Parser a -> String -> Maybe a
runParser (Parser p) s = case p s of
  Just (r, "") -> Just r
  _            -> Nothing

check :: (Char -> Bool) -> Parser Char
check f = Parser $ \s -> case s of
  (x:xs) | f x -> Just (x, xs)
  _            -> Nothing

char :: Char -> Parser Char
char c = check (== c)

oneOf :: String -> Parser Char
oneOf cs = check (`elem` cs)

number :: Parser Integer
number = read <$> some digit
  where digit = oneOf "0123456789"

expr :: Parser Expr
expr = add_sub
  where
    add_sub = binOp Add '+' mul <|> binOp Sub '-' mul <|> mul
    mul = binOp Mul '*' factor <|> factor
    div = binOp Div '/' div <|> div
    factor = parens <|> lit
    lit = Lit <$> number
    parens = char '(' *> expr <* char ')'
    binOp c o p = c <$> p <*> (char o *> p)

evalExpr :: String -> Maybe Integer
evalExpr s = fmap eval $ runParser expr $ concat $ words s

main :: IO ()
main = do
    x <- getArgs
    print $ evalExpr $ unwords x


-- data Expr = Add Expr Expr
--           | Sub Expr Expr
--           | Mul Expr Expr
--           | Div Expr Expr
--           | Lit Integer

-- data Nul = Zero deriving (Eq)

-- -- data Day = Monday | Tuesday | W-- import System.Environment ( getArgs )
-- import Control.Applicative ( Alternative((<|>), empty, some) )
-- import Main (evalExpr)ednesday | Thursday | Friday | Saturday | Sunday
--            deriving (Eq, Ord, Show, Read, Bounded, Enum)

-- newtype Parser a = Parser {parse :: String -> Maybe (a, String)}

-- type Parser a = String -> Maybe (a, String) | Nothing

-- newtype Elem = Elem (Char, String)

-- newtype Oper a = Double a deriving (Show)

-- plus :: Double -> Double -> Double
-- plus a b = a + b

-- parseChar :: Char -> Parser Char
-- parseChar _ [] = Nothing
-- parseChar y (x:xs) = if  y == x
--     then Just (x, xs)
--     else  Nothing

-- parseAnyChar :: String -> Parser Char
-- parseAnyChar [] _ = Nothing
-- parseAnyChar _ [] = Nothing
-- parseAnyChar (x:xs) (y:ys) | x == y = Just (y, ys)
--      | otherwise = parseAnyChar xs (y:ys)
-- -- parseAnyChar (x:xs) (y:ys) = case x of
-- --     y -> Just (y, ys)
-- --     x -> parseAnyChar xs (y:ys)

-- parseOr :: Parser a -> Parser a -> Parser a
-- parseOr x y str = case x str of
--     Nothing -> y str
--     Just (c, str') -> x str
-- -- parseOr x y b | isJust (x b) = x b
-- --                 | otherwise = y b

-- parseAnd :: Parser a -> Parser b -> Parser (a, b)
-- -- parseAnd x y z | isJust (x z) && isJust (y (snd res)) = Just ((fst res, fst res2), snd res2)
-- --                 | otherwise = Nothing
-- --                 where
-- --                     res = fromJust (x z)
-- --                     res2 = fromJust (y (snd res))
-- parseAnd left right str = case left str of
--     Nothing -> Nothing
--     Just (c, str') -> case right str' of
--         Nothing -> Nothing
--         Just (c', str'') -> Just ((c, c'), str'')

-- parseAndWith :: (a -> b -> c) -> Parser a -> Parser b -> Parser c
-- parseAndWith f x y str = case parseAnd x y str of
--     Nothing -> Nothing
--     Just ((c,c'), str') -> Just (f c c' , str')
-- -- parseAndWith r x y z | isJust (x z) && isJust (y (tail z)) = r ((fst res, fst res2), snd res2)
-- --                 | otherwise = Nothing
-- --                 where
-- --                     res = fromJust (x z)
-- --                     res2 = fromJust (y (snd res))

-- parseMany :: Parser a -> Parser [a]
-- parseMany x str = case x str of
--     Nothing -> Just (empty, str)
--     Just (c, str') -> Just (c : fst (fromJust (parseMany x str')), snd (fromJust (parseMany x str')))

-- -- many :: Alternative f => f a -> f [a]
-- -- many p = ((:) <$> p <*> many p) <|> pure []

-- charToString :: Char -> String
-- charToString c = [c]

-- -- parseSome :: Parser a -> Parser [a]
-- -- parseSome x str = case x str of
-- --     Nothing -> Just (empty, str)
-- --     Just (c, str') -> if c == empty then Nothing
-- --         else Just (c : fst (fromJust (parseSome x str')), snd (fromJust (parseSome x str')))

-- -- main :: IO ()
-- -- main = do
-- --     print (parseMany (parseChar ' ') "   test")