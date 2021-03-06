#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <sys/time.h>
#include <assert.h>
using namespace std;

// Quicksort
void quickSort(int a[], int p, int r);
int partition(int a[], int p, int r);

// BubbleSort
void bubbleSort(int array[]);

// InsertionSort
void insertionSort(int arr[], int length);

// Get unsorted lists of integers
void getList(int array[], int listSize,  int listNum);

// Print array contents
void printList(int array[]);

// Check to see that array is sorted 0..n
bool isSorted(int a[], int size);

// Check to see that array is sorted n..0
bool isSortedR(int a[], int size);




int main(int argc, char** argv)
{
    int sizes[11] = {10,50,100,500,1000,5000, 10000, 50000, 100000, 500000, 1000000}; // the sizes of lists
    
    // THIS WON'T WORK:
    int ** array;
    for (int i = 0; i < 11; i++)
    {
    int listNum = 1; // 1-1000
    ofstream outFile;
    outFile.open ("output.csv");
    outFile << "n, BubbleSort, QuickSort, InsertionSort, MergeSort\n";

    timeval t1;
    timeval t2;

    while (listNum <= 100)
    {
        getList(array, listSize, listNum);
        // cout << "unsorted list:";
        // printList(array);
        // cout << "}\n";

        // Bubble Sort
        gettimeofday(&t1, NULL);
        bubbleSort(array);
        gettimeofday(&t2, NULL);

        // make sure list is sorted
        assert(isSorted(array, listSize));

        //cout << "bubbleSorted list:\n{";
        //printList(array);
        //cout << "}\n";

        //    cout << "t1: " << t1.tv_usec << ", t2: " << t2.tv_usec << endl;
        //    cout << "bubbleSort execution time on n = "<< listSize << ": " << t2.tv_usec - t1.tv_usec << endl;
        outFile << listSize
                << ","
                <<  (t2.tv_sec + (t2.tv_usec / 1000000)) -
                    (t1.tv_sec +(t1.tv_usec / 1000000))
                << ",";
        getList(array, listSize, listNum);
    /*
     cout << "unsorted list:\n{";
    printList(array);
     cout << "}\n";
     */

    // Quick Sort
        gettimeofday(&t1, NULL);
        quickSort(array, 0, listSize);
        gettimeofday(&t2, NULL);
        assert(isSortedR(array, listSize));

        cout << "quickSorted list:\n";
        printList(array);
        cout    << "t2.tv_usec: " << t2.tv_usec << endl << "t2.tv_sec: "
                << t2.tv_sec << endl;


//    cout << "quickSort execution time on n = "<< listSize << ": " << t2.tv_usec - t1.tv_usec << endl;
        outFile << t2.tv_usec - t1.tv_usec << ",";

        getList(array, listSize, listNum);
    /*
    cout << "unSorted list:\n{";
        printList(array);
        cout << "}\n";
    */

        gettimeofday(&t1, NULL);
        insertionSort(array, listSize);
        gettimeofday(&t2, NULL);
        assert(isSorted(array, listSize));

    /*
    cout << "insertionSorted list:\n{";
    printList(array);
    cout << "}\n";
    */

//    cout << "insertionSort execution time on n = "<< listSize << ": " << t2.tv_usec - t1.tv_usec << endl;
        outFile << t2.tv_usec - t1.tv_usec << "\n";
        ++listNum;
    }
    outFile.close();
    return 0;
}

void bubbleSort(int array[])
{
    int swap;
    do{
        swap = 0;
        int n = 1;
        while (array[n] != '\0')
        {
            if (array[n-1] > array[n])
            {
                swap = 1;
                int temp = array[n-1];
                array[n-1] = array[n];
                array[n] = temp;
            }
            ++n;
        }
    }while(swap == 1);
}

int partition(int a[], int p, int r) {
    int x = a[r];
    int j = p - 1;
    for (int i = p; i < r; i++) {

        if (x <= a[i]) {
            j = j + 1;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    a[r] = a[j + 1];
    a[j + 1] = x;

    return (j + 1);
}

void quickSort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

void getList(int array[], int listSize, int listNum)
{
    stringstream ss;
    ss << listSize;
    string strSize = ss.str();
    ss.str("");
    ss << listNum;
    string strNum = ss.str();
    ss.str("");

    string filename = "../../lists/size" + strSize + "/list" + strNum;


    ifstream myfile (filename); //opening the file.
    if(myfile.is_open()) //if the file is open
    {
        int n = 0;
        while (!myfile.eof()) //while the end of file is NOT reached
        {
            myfile >> array[n];
            n++;
        }
        array[n] = '\0';
        myfile.close(); //closing the file

    }
    else {
        cerr << "Unable to open file\n"; //if the file is not open output
        exit(0);
    }
}

void printList(int array[])
{
    int n = 0;
    cout << "{";
    while (array[n] != '\0')
    {
        cout << array[n] << ", ";
        ++n;
    }
    cout << "}\n";
}

void insertionSort(int arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

bool isSorted(int a[], int size)
{
  int i;
  for(i = 0; i < (size-1); i++)
    if (a[i] > a[i+1])
      return false;
  return true;
}

bool isSortedR(int a[], int size)
{
  int i;
  for(i = 0; i < (size-1); i++)
    if (a[i] < a[i+1])
      return false;
  return true;
}
