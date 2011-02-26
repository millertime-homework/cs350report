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

def quicksort(the_list):
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

if __name__=="__main__":
    main()
