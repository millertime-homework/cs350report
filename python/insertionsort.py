#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# insertionsort.py
# InsertionSort - implemented in Python

import sys
from sort_utils import getlist

def main():
    """Handle the argument list"""
    if len(sys.argv) != 2:
        print("Fail! Supply filename")
    l = getlist(sys.argv[1])
    print(l)
    sl = insertionsort(l)
    print(sl)

def insertionsort(l):
    """Algorithm found on Wikipedia"""
    n = len(l)
    for j in range(1,n):
        key = l[j]
        i = j - 1
        while i >= 0 and l[i] > key:
            l[i+1] = l[i]
            i -= 1
        l[i+1] = key
    return l

if __name__=="__main__":
    main()
