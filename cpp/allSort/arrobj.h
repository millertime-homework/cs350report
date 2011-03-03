#ifndef ARROBJ_H
#define ARROBJ_H

class arrObj
{
public:
    arrObj(int);
    ~arrObj();
    void quickSort();
    void insertionSort();
    void bubbleSort();

private:
    int *array;
    int arrSize;
};
#endif
