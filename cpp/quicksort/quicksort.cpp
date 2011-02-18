#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "quicksort.h"
using namespace std;

void quicksort(int a[], int lo, int hi) 
{
  if (hi > lo) {
    int q = partition(a, lo, hi);
    quicksort(a, lo, q);
    quicksort(a, q+1, hi);
  }
}

int partition(int a[], int lo, int hi)
{
  int pivot = a[lo];
  int i = lo - 1;
  int j = hi + 1;
  while(true) {
    while(a[--j] > pivot);
    while(a[++i] < pivot);
    if (i<j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    } else
      return j;
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

void printArray(int a[], int size)
{
  int i;
  cout << "[";
  for(i = 0; i < (size - 1); i++)
    cout << a[i] << ", ";
  cout << a[size-1] << "]\n";
}

int main() 
{
  srand(time(NULL));
  int t;
  int num_tests = 100000;
  for(t = 0; t < num_tests; t++) {
    // generate random sized array..
    int size = rand() % 2500000 + 1;
    int i;
    int array[size];
    // generate random numbers to fill array
    for(i = 0; i < size; i++) {
      array[i] = (rand() % 100 + 1);
    }
    quicksort(array, 0, size-1);
    assert(isSorted(array,size));
  }
  cout << num_tests << " tests completed successfully.\n";
  return 0;
}
