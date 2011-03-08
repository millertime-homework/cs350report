#ifndef ARROBJ_H
#define ARROBJ_H

#include <list>
using std::list;

class arrObj
{
public:
    arrObj(int);
    ~arrObj();
    void getList(int);
    void quickSort(int, int);
    int partition(int, int);
    void insertionSort();
    void bubbleSort();
    void mergeSort();
    void merge();
    void printList(int *);
    bool isSorted(int *);
    bool isMergeSorted();

private:
    int *arrBubble;
    int *arrQuick;
    int *arrInsertion;
    list<int> mergeList;
    int arrSize;
};
#endif
