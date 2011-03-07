#ifndef ARROBJ_H
#define ARROBJ_H

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
    void merge_sort(int,int);
    void merge(int,int,int);
    void printList(int *);
    bool isSorted(int *);

private:
    int *arrBubble;
    int *arrQuick;
    int *arrInsertion;
    int *arrMerge;
    int arrSize;
};
#endif
