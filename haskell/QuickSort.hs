module QuickSort where

-- http://en.literateprograms.org/Quicksort_(Haskell)
-- http://en.wikipedia.org/wiki/Quicksort

quickSort [] = []
quickSort [x] = [x]
quickSort (pivot:xs) = (quickSort smaller) ++ [pivot] ++ (quickSort larger)
  where smaller = filter (<= pivot) xs
	larger  = filter (> pivot) xs
