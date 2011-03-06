#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# mergesort.py
# MergeSort - implemented in Python

from sort_utils import getlist,tail_rec

def main():
    """Handle the argument list"""
    if len(sys.argv) != 2:
        print("Fail! Supply filename")
    l = getlist(sys.argv[1])
    sl = mergesort(l)
    print(sl)

def tail_mergesort(l):
    """Split list in half and recurse"""
    if len(l) <= 1:
        return l
    split = len(l)/2
    return merge(mergesort(l[:split]), mergesort(l[split:]))

mergesort = tail_rec(tail_mergesort)

def tail_merge(x,y):
    """Merge two lists together"""
    if not x:
        return y
    if not y:
        return x
    if x[0] <= y[0]:
        return [x[0]] + merge(x[1:], y)
    else:
        return [y[0]] + merge(x, y[1:])

merge = tail_rec(tail_merge)

if __name__=="__main__":
    main()
