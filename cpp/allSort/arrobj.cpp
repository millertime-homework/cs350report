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
	mergeList.push_front(atoi(line.c_str()));
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

void arrObj::do_mergeSort()
{
  list<int> dummy = mergeSort(mergeList);
  assert(isMergeSorted(dummy));
}

list<int> arrObj::mergeSort(list<int> a)
{
  int n = mergeList.size();
  if (n <= 1)
    return a;
  int middle = n / 2;
  list<int> right = a;
  list<int> left;
  list<int> result;
  for(int i = 0; i < middle; i++) {
    left.push_back(right.front());
    right.pop_front();
  }
  assert(left.size() + right.size() == a.size());
  left = mergeSort(left);
  right = mergeSort(right);
  result = merge(left, right);
  return result;
}

list<int> arrObj::merge(list<int> a, list<int> b)
{
  list<int> result;
  while ((a.size() > 0) || (b.size() > 0)) {
    if ((a.size() > 0) && (b.size() > 0)) {
      if (a.front() <= b.front()) {
        result.push_back(a.front());
        a.pop_front();
      } else {
        result.push_back(b.front());
        b.pop_front();
      }
    } else if (a.size() > 0) {
      result.push_back(a.front());
      a.pop_front();
    } else if (b.size() > 0) {
      result.push_back(b.front());
      b.pop_front();
    }
  }
  return result;
}

bool arrObj::isMergeSorted(list<int> a)
{
  list<int> testList = a;
    testList.sort();
    return (testList == a);
}

bool arrObj::isSorted(int *a)
{
    int i;
    for(i = 0; i < (arrSize-1); i++)
        if (a[i] > a[i+1])
            return false;
    return true;
}
