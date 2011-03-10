#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "arrobj.h"
#include <sys/time.h>
#include <stdio.h>
#include <math.h>
using namespace std;

//http://www.physicsforums.com/showthread.php?t=224989
double diffclock(clock_t t1, clock_t t2)
{
  double diffticks = t2 - t1;
  double diffms = diffticks / (double)CLOCKS_PER_SEC;
  return diffms;
}

int main()
{
    // We will sort unsorted lists of size:
    int sizes[11] = {10,50,100,500,1000,5000,10000,
                        50000,100000,500000,1000000};
    ofstream outFile;
    outFile.open("cpp-results.csv");
    outFile << "n, BubbleSort, InsertionSort, QuickSort, MergeSort\n";

    string toFile;
    for(int j = 0; j < 9; j++)
    {
        for(int i = 1; i <= 100; i++)
        {
            clock_t t1, t2;
            arrObj * my_arrays = new arrObj(sizes[j]);
            my_arrays->getList(i);

            stringstream ss;
            ss << sizes[j]<< ",";
            toFile += ss.str();
            ss.str("");

	    t1 = clock();
            my_arrays->bubbleSort();
	    t2 = clock();
            ss << diffclock(t1, t2);
            toFile += ss.str() + ",";
            ss.str("");

	    t1 = clock();
            my_arrays->insertionSort();
	    t2 = clock();
            ss << diffclock(t1, t2);
            toFile += ss.str() + ",";
            ss.str("");

            time(&t1);
            my_arrays->do_quickSort();
            time(&t2);
            ss << diffclock(t1, t2);
            toFile += ss.str() + ",";
            ss.str("");

	    time(&t1);
	    my_arrays->do_mergeSort();
	    time(&t2);
            ss << diffclock(t1, t2);
            toFile += ss.str() + "\n";
	    
	    delete my_arrays;
        }
    }
    outFile << toFile;
    outFile.close();

}

