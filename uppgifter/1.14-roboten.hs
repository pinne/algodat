match :: String -> Bool
match x
    | x == "ABCDE" = True
    | otherwise    = False

rswap x = x !! 1 : x !! 0 : drop 2 x

rshift x = last x : take 4 x

move :: ([Char], Int) -> [Char]
move (x:xs,n)
    | match [x] == True = x:[]
    | otherwise	      = move (rswap [x], n + 1)

