#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# quicksort.py
# QuickSort - implemented in Python

import sys

def main():
    """Handle the argument list"""
    if len(sys.argv) != 2:
        print("Fail! Supply filename")
    l = getlist(sys.argv[1])
    sl = quicksort(l)
    print(sl)

def getlist(filename):
    """Open and read file, massage string into list"""
    f = open(filename)
    s = f.read()
    f.close()
    l = map(int, s.split("\n"))
    return l

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
