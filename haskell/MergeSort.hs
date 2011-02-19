module MergeSort where

-- http://www.csc.depauw.edu/~bhoward/courses/0203Spring/csc122/haskintro/

merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x <= y
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys

mergesort [] = []
mergesort [x] = [x]
mergesort xs = let (as, bs) = splitAt (length xs `quot` 2) xs
               in merge (mergesort as) (mergesort bs)
