#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# timer.py
# Run each sort and time them

import time
from sort_utils import *
from bubblesort import *
from insertionsort import *
from mergesort import *
from quicksort import *

def main():
    """Start timer, sort, stop timer. write result to file"""
    for i in range(1,1001):
        l = getlist("../size10/list" + str(i))
        start = time.time()
        bubblesort(l)
        bubble_time = time.time() - start
        start = time.time()
        insertionsort(l)
        insertion_time = time.time() - start
        start = time.time()
        mergesort(l)
        merge_time = time.time() - start
        start = time.time()
        quicksort(l)
        quick_time = time.time() - start
        f = open("bubble10", 'a')
        f.write(str(bubble_time) + '\n')
        f.close()
        f = open("insertion10", 'a')
        f.write(str(insertion_time) + '\n')
        f.close()
        f = open("merge10", 'a')
        f.write(str(merge_time) + '\n')
        f.close()
        f = open("quick10", 'a')
        f.write(str(quick_time) + '\n')
        f.close()

if __name__=="__main__":
    main()
