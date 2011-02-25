#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# sort_utils.py
# Some helpers for building up lists and sorting

def getlist(filename):
    """Open and read file, massage string into list"""
    f = open(filename)
    s = f.read()
    f.close()
    l = map(int, s.split("\n"))
    return l
