#include "arrobj.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;

arrObj::arrObj(int s): arrSize(s)
{
    arrBubble = new int[arrSize];
    arrQuick = new int[arrSize];
    arrInsertion = new int[arrSize];
}

arrObj::~arrObj()
{
    delete [] arrBubble;
    delete [] arrQuick;
    delete [] arrInsertion;
}

void arrObj::bubbleSort()
{
    int swap;
    do{
        swap = 0;
        for (int n = 1; n < arrSize; n++) {
            if (arrBubble[n-1] > arrBubble[n]) {
                swap = 1;
                int temp = arrBubble[n-1];
                arrBubble[n-1] = arrBubble[n];
                arrBubble[n] = temp;
            }
        }
    }while(swap == 1);
    //assert(isSorted(arrBubble));

}
int arrObj::partition(int p, int r) {
    int x = arrQuick[r];
    int j = p - 1;
    for (int i = p; i < r; i++) {
        if (x <= arrQuick[i]) {
            j = j + 1;
            int temp = arrQuick[j];
            arrQuick[j] = arrQuick[i];
            arrQuick[i] = temp;
        }
    }
    arrQuick[r] = arrQuick[j + 1];
    arrQuick[j + 1] = x;
    return (j + 1);
}

void arrObj::quickSort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

void arrObj::getList(int listNum)
{
    stringstream ss;
    ss << arrSize;
    string strSize = ss.str();
    ss.str("");
    ss << listNum;
    string strNum = ss.str();
    ss.str("");

    string filename = "../../lists/size" + strSize + "/list" + strNum;

    ifstream f(filename.c_str(), ifstream::in);
    string line;
    if (f) {
        int i = 0;
        while (getline(f, line) != 0) {
        arrBubble[i] = atoi(line.c_str());
        arrQuick[i] = atoi(line.c_str());
        arrInsertion[i] = atoi(line.c_str());

        i++;
        }
    f.close();
    }
    else {
        cerr << "Unable to open file\n"; //if the file is not open output
        exit(0);
    }
}

void arrObj::printList(int *array)
{
    cout << arrSize << endl;
    cout << "{";
    for (int n = 0; n < arrSize; n++) {
        cout << array[n] << ", ";
    }
    cout << "}\n";
}

void arrObj::insertionSort()
{
    int i, j, tmp;
    for (i = 1; i < arrSize; i++) {
        j = i;
        while (j > 0 && arrInsertion[j - 1] > arrInsertion[j]) {
            tmp = arrInsertion[j];
            arrInsertion[j] = arrInsertion[j - 1];
            arrInsertion[j - 1] = tmp;
            j--;
        }
    }
    //assert(isSorted(arrInsertion));
}

void arrObj::merge_sort(int low,int high)
{
    int mid;
    if(low<high) {
        mid=(low+high)/2;
	merge_sort(low,mid);
	merge_sort(mid+1,high);
	merge(low,mid,high);
    }
}

void merge(int low,int mid,int high)
{
    int h,i,j,b[50],k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high)) {
        if(a[h]<=a[j]) {
	    b[i]=a[h];
	    h++;
	} else {
	    b[i]=a[j];
	    j++;
	}
	i++;
    }
    if(h>mid) {
        for(k=j;k<=high;k++) {
	    b[i]=a[k];
	    i++;
	}
    } else {
        for(k=h;k<=mid;k++) {
	    b[i]=a[k];
	    i++;
	}
    }
    for(k=low;k<=high;k++) 
        a[k]=b[k];
}


bool arrObj::isSorted(int *a)
{
  int i;
  for(i = 0; i < (arrSize-1); i++)
    if (a[i] > a[i+1])
      return false;
  return true;
}
