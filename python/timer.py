#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# timer.py
# Run each sort and time them

import time,sys
from sort_utils import *
from bubblesort import *
from insertionsort import *
from mergesort import *
from quicksort import *

def main():
    """Start timer, sort, stop timer. write result to file"""
    #sizes = [10,50,100,500,1000,5000,10000,50000,100000,500000,1000000]
    b_times = []
    i_times = []
    m_times = []
    q_times = []
    size = 50000
#for size in sizes:
    for num in range(1,101):
        l = getlist("../lists/size" + str(size) + "/list" + str(num))
        start = time.time()
        bubblesort(l)
        b_times.append((size,time.time() - start))
        start = time.time()
        insertionsort(l)
        i_times.append((size,time.time() - start))
        start = time.time()
        mergesort(l)
        m_times.append((size,time.time() - start))
        start = time.time()
        quicksort(l)
        q_times.append((size,time.time() - start))
    csv = "n,bubble,insertion,merge,quick\n"
    #for size in sizes:
    for i in range(100):
        csv += str(b_times[i][0]) + ',' + str(b_times[i][1]) + ','
        csv += str(i_times[i][1]) + ',' + str(m_times[i][1]) + ','
        csv += str(m_times[i][1]) + '\n'
    f = open("size50000-python.csv", 'w')
    f.write(csv)
    f.close()

if __name__=="__main__":
    main()
