#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Quicksort
void quickSort(int a[], int p, int r);
int partition(int a[], int p, int r);
// BubbleSort
void bubbleSort(int array[]);

main(int argc, char** argv)
{
        if (argc != 2)
	{
                printf("Nope! Like this: ./bubbles n\n");
                return 0;
        }

        int userNum = atoi(&argv[1][0]);
	cout << "userNum: " << userNum << endl;
	int array[userNum + 1]; // creates array to hold names
	int n = 0; 
	ifstream myfile ("../../size1000/list998"); //opening the file.
    
	if(myfile.is_open()) //if the file is open
	{
		while (!myfile.eof() && (n < userNum)) //while the end of file is NOT reached
		{
			myfile >> array[n];
            		n++;
        	}
		array[n] = '\0';
		myfile.close(); //closing the file

	}
	else cout << "Unable to open file"; //if the file is not open output

	n = 0;
        cout << "unsorted list:\n{";
        while (array[n] != '\0')
        {
                cout << array[n] << ", ";
                ++n;
        }	
        cout << "}\n";

	int t1 = clock();
        //bubbleSort(array);
	int t2 = clock();
	quickSort(array, 0, 1000);
	int t3 = clock();
        n = 0;
        cout << "sorted list:\n{";
        while (array[n] != '\0')
        {
                cout << array[n] << ", ";
                ++n;
        }
        cout << "}\n";
	cout << "t1: " << t1 << ", t2: " << t2 << endl;
	cout << "BubbleSort execution time on n = "<< userNum << ": " << t2-t1 << endl;
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
