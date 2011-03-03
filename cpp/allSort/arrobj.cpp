#include "arrobj.h"

arrObj::arrObj(int s): arrSize(s)
{
    array = new int[arrSize];
}

arrObj::~arrObj()
{
    delete [] array;
}

void arrObj::bubbleSort()
{
    int swap;
    do{
        swap = 0;
        int n = 1;
        for (int n = 1; n < arrSize; n++)
        {
            if (array[n-1] > array[n])
            {
                swap = 1;
                int temp = array[n-1];
                array[n-1] = array[n];
                array[n] = temp;
            }
        }
    }while(swap == 1);
}
/*
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

*/
