#include "arrobj.h"
#include <sys/time.h>

int main()
{
    for(int i = 1; i < 10; i++)
    {
        arrObj my_array(i);
    }

    gettimeofday(&t1, NULL);
    my_array.bubbleSort();
    gettimeofday(&t2, NULL);






}

