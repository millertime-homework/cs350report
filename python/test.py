#!/usr/bin/python

from sort_utils import *
from quicksort import *
from mergesort import *
from bubblesort import *
from insertionsort import *

def main():
    """Try all of the size10 lists"""
    for i in range(1,101):
        l = getlist("../lists/size10/list" + str(i))
        assert(sorted(l) == quicksort(l))
        assert(sorted(l) == mergesort(l))
        assert(sorted(l) == bubblesort(l))
        assert(sorted(l) == insertionsort(l))
    print("done")

if __name__=="__main__":
    main()
