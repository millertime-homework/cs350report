#include <iostream>
using namespace std;


void bubbleSort(int array[]);
int main()
{
	int list[] = {8, 3, 5, 6, 1, 2, 4, 9, 7};
	int n = 0;
	cout << "unsorted list:\n{";
	while (list[n] != '\0')
	{
		cout << list[n] << ", "; 
		++n;
	}
	cout << "}\n";
	bubbleSort(list);
	return 0;
}

void bubbleSort(int array[])
{
	do{
		int n = 1;
		int swap = 0;
		while (array[n] != '\0')
		{
			if (array[n-1] > array[n])
			{
				swap = 1;
				int temp = array[n-1];
				array[n-1] = array[n];
				array[n] = temp;
			}
			++n;
		}
	}while(swap == 1);
}


/*  do{
    swapped = false
    for each i in 1 to length(A) - 1 inclusive do:
      if A[i-1] > A[i] then
        swap( A[i-1], A[i] )
        swapped = true
      end if
    end for
  while swapped
end procedure
*/
