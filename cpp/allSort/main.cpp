#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "arrobj.h"
#include <sys/time.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    // We will sort unsorted lists of size:
    int sizes[11] = {10,50,100,500,1000,5000,10000,
                        50000,100000,500000,1000000};
    ofstream outFile;
    outFile.open("output.csv");
    outFile << "n, BubbleSort, QuickSort, InsertionSort, MergeSort\n";

    string toFile;
    for(int j = 0; j < 1; j++)
    {
        for(int i = 1; i <= 1; i++)
        {
            time_t t1, t2;
            arrObj my_arrays(sizes[j]);
            my_arrays.getList(i);

            stringstream ss;
            ss << sizes[j]<< ",";
            toFile += ss.str();
            ss.str("");

            time(&t1);
            my_arrays.bubbleSort();
            time(&t2);
            ss << t2 - t1;
            toFile += ss.str() + ",";
            ss.str("");

            time(&t1);
            my_arrays.insertionSort();
            time(&t2);
            ss << t2 - t1;
            toFile += ss.str() + ",";
            ss.str("");

            time(&t1);
            my_arrays.quickSort(0, sizes[j]);
            time(&t2);
            ss << t2 - t1;
            toFile += ss.str() + ",";
            ss.str("");

            toFile += ss.str() + "\n";
        }
    }
    outFile << toFile;
    outFile.close();

}

