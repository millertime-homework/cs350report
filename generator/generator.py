#!/usr/bin/python

# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# generator.py
# Main wrapper program for launching separate algorithms

import re, time
from subprocess import Popen, PIPE

def main():
    """Load configurations and launch each command"""
    commands = []
    f = open("commands")
    for line in f:
        commands.append(line)
    f.close()

    for command in commands:
        start = time.time()
        res = Popen(command, shell=True, stdout=PIPE)
        elapsed = time.time() - start
        print(str(elapsed))

if __name__=="__main__":
    main()
