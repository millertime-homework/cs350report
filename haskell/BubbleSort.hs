module BubbleSort where
-- Bubble Sort
-- Thank you Tim Sheard for sharing this code in CS163

bubble lhs [x] = (lhs,x)
bubble lhs (x:y:zs) | x <= y = bubble (lhs ++ [x]) (y:zs)
                    | x >  y = bubble (lhs ++ [y]) (x:zs)

bubbleSort [] = []
bubbleSort xs = iterate xs []
  where iterate [] ans = ans
        iterate xs ans = iterate rest (biggest : ans)
          where (rest,biggest) = bubble [] xs