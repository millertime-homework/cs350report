#!/usr/bin/python

from quicksort import *

def main():
    """Try all of the size10 lists"""
    for i in range(1,999):
        l = getlist("../size10/list" + str(i))
        assert(sorted(l) == sortit(l))
    print("done")

if __name__=="__main__":
    main()
