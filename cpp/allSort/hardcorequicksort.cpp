#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ofstream;

int * array;
  
//http://www.physicsforums.com/showthread.php?t=224989                                                                                                                            
double diffclock(clock_t t1, clock_t t2)
{
  double diffticks = t2 - t1;
  double diffms = diffticks / (double)CLOCKS_PER_SEC;
  return diffms;
}

void quicksort(int left, int right) {
  int pivot;
  int left_index = left;
  int right_index = right;
  if ((right - left) > 0) {
    pivot = (left + right) / 2;
    while ((left_index <= pivot) && (right_index >= pivot)) {
      while ((array[left_index] < array[pivot]) && (left_index <= pivot)) {
        ++left_index;
      }
      while ((array[right_index] > array[pivot]) && (right_index >= pivot)) {
        --right_index;
      }
      int tmp = array[left_index];
      array[left_index] = array[right_index];
      array[right_index] = tmp;
      ++left_index;
      --right_index;
      if (left_index - 1 == pivot) {
        pivot = right_index = right_index + 1;
      } else if (right_index + 1 == pivot) {
        pivot = left_index = left_index - 1;
      }
    }
    quicksort(left, pivot - 1);
    quicksort(pivot + 1, right);
  }
}

int main()
{
  srand(time(NULL));
  stringstream ss;
  string results = "n,quicksort\n";
  for(int size = 100000; size <= 100000000; size += 5000000) {
    array = new int[size];
    for(int i = 0; i < size; i++) {
      array[i] = rand() % 99999 + 1;
    }
    clock_t t1,t2;
    t1 = clock();
    quicksort(0, size - 1);
    t2 = clock();
    ss << diffclock(t1,t2);
    string clocktime = ss.str();
    ss.str("");
    ss << size;
    string ssize = ss.str();
    ss.str("");
    results += ssize + "," + clocktime + "\n";
    delete [] array;
  }
  ofstream o("quick-hardcore.csv");
  o << results;
  o.close();
  return 0;
}
