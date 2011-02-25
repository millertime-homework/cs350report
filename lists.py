#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# lists.py
# Generate random lists of different sizes

import sys, random
from subprocess import Popen,PIPE

def main():
    """Handle the argv"""
    if len(sys.argv) != 2:
        print("Yo dawg. You did it wrong. It's `python lists.py n`")
        exit()
    makelists(sys.argv[1])

def makelists(n):
    """Create a directory called dirname and generate n-sized lists in it"""
    Popen("mkdir size" + str(n), shell=True, stdout=PIPE)
    for i in range(1,1001):
        newlist = []
        for j in range(int(n)):
            newlist.append(random.randint(1,1000000))
        f = open("size" + n + "/list" + str(i), 'w')
        f.write("\n".join(map(str, (newlist))))
        f.close()

if __name__=="__main__":
    main()
