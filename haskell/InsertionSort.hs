module InsertionSort where

-- http://en.literateprograms.org/Insertion_sort_(Haskell)

insert elem [] = [elem]
insert elem (item : xs) | elem == item  = elem : item : xs
insert elem (item : xs) | elem < item   = elem : item : xs
insert elem (item : xs) | elem > item   = item: (insert elem xs)


sortInsert :: Ord a => [a] -> [a]
sortInsert [] = []
sortInsert (x:xs) =  insert x (sortInsert xs)