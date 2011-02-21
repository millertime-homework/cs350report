#!/usr/bin/python

from quicksort import *
from mergesort import *

def main():
    """Try all of the size10 lists"""
    for i in range(1,999):
        l = getlist("../size10/list" + str(i))
        assert(sorted(l) == quicksort(l))
        assert(sorted(l) == mergesort(l))
    print("done")

if __name__=="__main__":
    main()
