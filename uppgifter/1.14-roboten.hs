rmatch :: String -> Bool
rmatch x
    | x == "ABCDE" = True
    | otherwise    = False

rswap x = x !! 1 : x !! 0 : drop 2 x

rshift x = last x : take 4 x

rmove :: ([a], Num) -> [a]
rmove 0 = []

