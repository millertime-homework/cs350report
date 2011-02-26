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
	    new AllSorts(10, name);
	}
    }

    private int array_size;
    private int [] array;
    private String filename;

    public AllSorts(int s, String fn) 
    {
	array_size = s;
	filename = new String(fn);
	array = new int[s];
	LoadArray();
	quickSort(0,s - 1);
    }

    public void LoadArray()
    {
	try {
	    FileInputStream fstream = new FileInputStream(filename);
	    DataInputStream in = new DataInputStream(fstream);
	    BufferedReader br = new BufferedReader(new InputStreamReader(in));
	    String line;
	    int i = -1;
	    while ((line = br.readLine()) != null) {
		array[++i] = Integer.parseInt(line);
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
	    System.out.println(array[i]);
	}
    }

    private void swap(int a, int b)
    {
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
    }

    public void quickSort(int left, int right)
    {
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
		swap(left_index, right_index);
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
}