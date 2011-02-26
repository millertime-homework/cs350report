#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <sys/time.h>
using namespace std;

// Quicksort
void quickSort(int a[], int p, int r);
int partition(int a[], int p, int r);

// BubbleSort
void bubbleSort(int array[]);

// InsertionSort
void insertionSort(int arr[], int length);

// Get unsorted lists of integers
void getList(int array[], int userNumI, char userNum[]);

// Print array contents
void printList(int array[]);

main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Nope! Like this: ./allSort n\n");
        return 0;
    }
	ofstream outFile;
  	outFile.open ("output.txt");
  	outFile << "BubbleSort, QuickSort, InsertionSort, MergeSort\n";
  	outFile.close();

    int userNum = atoi(&argv[1][0]);
    int array[userNum + 1]; // creates array to hold names
    getList(array, userNum, &argv[1][0]);

    /*
       cout << "unsorted list:\n{";
       printList(array);
       cout << "}\n";
     */

    timeval t1;
    timeval t2;

    // Bubble Sort	
    gettimeofday(&t1, NULL);
    bubbleSort(array);
    gettimeofday(&t2, NULL);

    /*
       cout << "bubbleSorted list:\n{";
       printList(array);
       cout << "}\n";

     */
    //cout << "t1: " << t1.tv_usec << ", t2: " << t2.tv_usec << endl;
    cout << "bubbleSort execution time on n = "<< userNum << ": " << t2.tv_usec - t1.tv_usec << endl;

    //getList(array, userNum);

    /*
       cout << "unsorted list:\n{";
       printList(array);
       cout << "}\n";
     */

    // Quick Sort	
    gettimeofday(&t1, NULL);
    quickSort(array, 0, 1000);
    gettimeofday(&t2, NULL);

    /*
       cout << "quickSorted list:\n{";
       printList(array);
       cout << "}\n";

       cout << "t1: " << t1 << ", t2: " << t2 << endl;
     */
    cout << "quickSort execution time on n = "<< userNum << ": " << t2.tv_usec - t1.tv_usec << endl;

    //getList(array, userNum);

	/*
	cout << "unSorted list:\n{";
    	printList(array);
    	cout << "}\n";
	*/

    gettimeofday(&t1, NULL);
    insertionSort(array, userNum);
    gettimeofday(&t2, NULL);

	/*
    cout << "insertionSorted list:\n{";
    printList(array);
    cout << "}\n";
	*/

    cout << "insertionSort execution time on n = "<< userNum << ": " << t2.tv_usec - t1.tv_usec << endl;

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

void getList(int array[], int userNumI, char userNum[])
{
    int n = 0;

	char pathName[20]; 
	strcpy (pathName, "../../size");
	strcat(pathName, userNum);
	strcat(pathName, "/");
	strcat(pathName, "list998");
	//char fileName[] = 	
    ifstream myfile (pathName); //opening the file.
    if(myfile.is_open()) //if the file is open
    {   
        while (!myfile.eof() && (n < userNumI)) //while the end of file is NOT reached
        {   
            myfile >> array[n];
            n++;
        }   
        array[n] = '\0';
        myfile.close(); //closing the file

    }   
    else cout << "Unable to open file"; //if the file is not open output
}

void printList(int array[])
{
    int n = 0;
    while (array[n] != '\0')
    {   
        cout << array[n] << ", ";
        ++n;
    }   
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
