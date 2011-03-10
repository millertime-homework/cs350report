/* 
 * Copyright 2011 Russell Miller & Ben Carr
 * Please see included LICENSE file
 *
 * HardcoreQuickSort
 * We decided we should spend some more time with our
 * all-star sorting algorithm
 */

import java.util.*;
import java.io.*;
import java.lang.RuntimeException;

public class HardcoreQuicksort
{

    public static void main(String [] args)
    {
	PrintWriter writer;
	String csvfile = "quicksort.csv";
	try {
	    writer = new PrintWriter(new BufferedWriter(new FileWriter(csvfile, false)));
	} catch (IOException e) {
	    throw new RuntimeException(e);
	}
	writer.print("");
	writer.close();
	HardcoreQuicksort thebeast;
	String results = new String("n,quick,bubble,insertion,merge\n");
	for(int size = 100000; size <= 10000000; size += 100000) {
        thebeast = new HardcoreQuicksort(size);
        results += size + "," + thebeast.getTimes() + "\n";
    }	    
    try {
		writer = new PrintWriter(new BufferedWriter(new FileWriter(csvfile, true)));
    } catch (IOException e) {
		throw new RuntimeException(e);
    }
    writer.append(results);
	writer.close();
	System.out.println("Done.");
    }
    
    private int array_size;
    private int [] array;     // Array quickSort will be sorting
    private float elapsed_time;
    private Random generator;

    public HardcoreQuicksort(int s) 
    {
        generator = new Random();
        array_size = s;
        array = new int[s];
        LoadArray();
        long start = System.currentTimeMillis();
        quickSort(0,s - 1);
        long elapsed = System.currentTimeMillis()-start;
        elapsed_time = elapsed/1000F;
    }

    public void LoadArray()
    {
        for(int i = 0; i < array_size; i++)
            array[i] = generator.nextInt(99999);
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
            quickSort(left, pivot - 1);
            quickSort(pivot + 1, right);
        }
    }
    
    public String getTimes()
    {
        String result = new String("");
        result += elapsed_time;
        return result;
    }
}