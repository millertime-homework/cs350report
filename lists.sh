#!/bin/bash
# Copyright 2011 Russell Miller & Ben Carr
# Please see included LICENSE file

# lists.sh
# Generate random lists of different sizes

# user error check/help
if [ $# -ne 1 ]; then
        echo "yo dawg, like this: './lists.sh n' "
	exit 0
fi

# get arg from user args
MAX=$1 

# make directory to store the files
mkdir size$MAX

# make 1000 files
for (( d=0; d<=1000; d++ )) 
do
	# generate a random list of numbers size MAX
	for (( c=1; c<=$MAX; c++ )) 
	do
		# store in the file
		echo $RANDOM >> size$MAX/list$d
	done
done

#fin

