#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void bubbleSort(int array[]);

main(int argc, char** argv)
{
        if (argc != 2)
	{
                printf("Nope! Like this: ./bubbles n\n");
                return 0;
        }

        int userNum = atoi(&argv[1][0]);
	int array[userNum + 1]; // creates array to hold names
	int n = 0; 

	ifstream myfile ("../../size20/list999"); //opening the file.
    
	if(myfile.is_open()) //if the file is open
	{
		while (!myfile.eof()) //while the end of file is NOT reached
		{
			myfile >> array[n];
            		n++;
        	}

	myfile.close(); //closing the file

	}
	else cout << "Unable to open file"; //if the file is not open output

	n = 0;
        cout << "unsorted list:\n{";
        while (array[n] != '\0')
        {
                cout << array[n] << ", ";
                ++n;
        }	
        cout << "}\n";

        bubbleSort(array);
        n = 0;
        cout << "sorted list:\n{";
        while (array[n] != '\0')
        {
                cout << array[n] << ", ";
                ++n;
        }
        cout << "}\n";
	return 0;
}

void bubbleSort(int array[])
{
        int swap;
        do{
                swap = 0;
                int n = 1;
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
