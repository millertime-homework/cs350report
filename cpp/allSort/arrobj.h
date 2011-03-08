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
    void printList(int *);
    bool isSorted(int *);
    bool isSortedR(int *);

private:
    int *arrBubble;
    int *arrQuick;
    int *arrInsertion;
    int arrSize;
};
#endif
