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
