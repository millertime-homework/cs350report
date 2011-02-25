#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# bubblesort.py
# BubbleSort - implemented in Python

import sys
from sort_utils import getlist

def main():
    """Handle the argument list"""
    if len(sys.argv) != 2:
        print("Fail! Supply filename")
    l = getlist(sys.argv[1])
    print(l)
    sl = bubblesort(l)
    print(sl)

def bubblesort(l):
    """Algorithm found on Wikipedia"""
    n = len(l)
    while True:
        newn = 0
        for i in range(n-1):
            if l[i] > l[i+1]:
                l[i],l[i+1] = l[i+1],l[i]
                newn = i + 1
        n = newn
        if (n <= 1):
            break
    return l

if __name__=="__main__":
    main()
