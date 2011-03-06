#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# quicksort.py
# QuickSort - implemented in Python

import sys
from sort_utils import getlist

def main():
    """Handle the argument list"""
    if len(sys.argv) != 2:
        print("Fail! Supply filename")
    l = getlist(sys.argv[1])
    sl = quicksort(l)
    print(sl)

def tail_rec(fun):
    """Tail recursion implementation found at
    http://paulbutler.org/archives/tail-recursion-in-python/
    and spotted by Tony Wooster -- many thanks sir"""
    def tail(fun):
        a = fun
        while callable(a):
            a = a()
        return a
    return (lambda x: tail(fun(x)))

def tail_quicksort(the_list):
    """QuickSort algorithm"""
    if len(the_list) <= 1:
        return the_list
    pivot = the_list[0]
    smaller = []
    larger = []
    for item in the_list[1:]:
        if item <= pivot:
            smaller.append(item)
        else:
            larger.append(item)
    return (quicksort(smaller) + [pivot] + quicksort(larger))

quicksort = tail_rec(tail_quicksort)

if __name__=="__main__":
    main()
