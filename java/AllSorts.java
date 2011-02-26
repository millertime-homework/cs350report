/* 
 * Copyright 2011 Russell Miller & Ben Carr
 * Please see included LICENSE file
 *
 * AllSorts - 
 * Merge, Bubble, Insertion, and Quick sort all implemented
 * in Java and execution timed for different sizes.
 */

import java.util.*;
import java.io.*;

public class AllSorts
{
    /* 
     * main!!
     * Just call the constructor.. to get out of staticyness..
     */
    public static void main(String [] args)
    {
	String name = new String("");
	int i;
	for(i = 1; i < 1000; i++) {
	    name = "../size10/list" + i;
	    try {
		new AllSorts(10, name);
	    } catch (Exception e) {
		System.out.println(e.getMessage());
	    }
	}
	System.out.println("Done.");
    }

    private int array_size;
    private int [] qs_array;
    private int [] bs_array;
    private String filename;

    public AllSorts(int s, String fn) 
    {
	array_size = s;
	filename = new String(fn);
	qs_array = new int[s];
	bs_array = new int[s];
	LoadArrays();
	// Make a copy of the original list..
	int [] test_arr = new int[s];
	int i;
	for(i = 0; i < s; i++) {
	    test_arr[i] = qs_array[i];
	}
	// Sort the main copy of the original list using quickSort,bubbleSort
	quickSort(0,s - 1);
	bubbleSort();
	// Sort the test copy using Java's built-in sort.
	Arrays.sort(test_arr);
	// Check that they're the same.
	for(i = 0; i < s; i++) {
	    assert (qs_array[i] == test_arr[i]);
	    assert (bs_array[i] == test_arr[i]);
	}
    }

    public void LoadArrays()
    {
	try {
	    FileInputStream fstream = new FileInputStream(filename);
	    DataInputStream in = new DataInputStream(fstream);
	    BufferedReader br = new BufferedReader(new InputStreamReader(in));
	    String line;
	    int i = 0;
	    while ((line = br.readLine()) != null) {
		qs_array[i] = Integer.parseInt(line);
		bs_array[i] = Integer.parseInt(line);
		++i;
	    }
	    in.close();
	} catch (Exception e) {
	    System.out.println(e.getMessage());
	}
    }
    
    public void printArray()
    {
	int i;
	for(i = 0; i < array_size; i++) {
	    System.out.println(qs_array[i]);
	}
    }

    private void qs_swap(int a, int b)
    {
	int tmp = qs_array[a];
	qs_array[a] = qs_array[b];
	qs_array[b] = tmp;
    }

    public void quickSort(int left, int right)
    {
	int pivot;
	int left_index = left;
	int right_index = right;
	if ((right - left) > 0) {
	    pivot = (left + right) / 2;
	    while ((left_index <= pivot) && (right_index >= pivot)) {
		while ((qs_array[left_index] < qs_array[pivot]) && (left_index <= pivot)) {
		    ++left_index;
		}
		while ((qs_array[right_index] > qs_array[pivot]) && (right_index >= pivot)) {
		    --right_index;
		}
		qs_swap(left_index, right_index);
		++left_index;
		--right_index;
		if (left_index - 1 == pivot) {
		    pivot = right_index = right_index + 1;
		} else if (right_index + 1 == pivot) {
		    pivot = left_index = left_index - 1;
		}
	    }
	    quickSort(left, pivot - 1);
	    quickSort(pivot + 1, right);
	}
    }

    private void bs_swap(int a, int b)
    {
	int tmp = bs_array[a];
	bs_array[a] = bs_array[b];
	bs_array[b] = tmp;
    }
    
    public void bubbleSort()
    {
	int n = array_size;
	do {
	    int newn = 0;
	    int i;
	    for(i = 0; i < n-1; i++) {
		if (bs_array[i] > bs_array[i+1]) {
		    bs_swap(i,i+1);
		    newn = i + 1;
		}
	    }
	    n = newn;
	} while (n > 1);
    }
}