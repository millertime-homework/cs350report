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
	    new AllSorts(name);
	}
    }

    private ArrayList<String> current_list;
    private String filename;

    public AllSorts(String fn) 
    {
	filename = new String(fn);
	current_list = new ArrayList<String>();
	LoadArray();
    }

    public void LoadArray()
    {
	try {
	    FileInputStream fstream = new FileInputStream(filename);
	    DataInputStream in = new DataInputStream(fstream);
	    BufferedReader br = new BufferedReader(new InputStreamReader(in));
	    String line;
	    while ((line = br.readLine()) != null) {
		current_list.add(line);
	    }
	    in.close();
	} catch (Exception e) {
	    System.out.println(e.getMessage());
	}
    }
    
    public void printArray()
    {
	int i;
	int l = current_list.size();
	for(i = 0; i < l; i++) {
	    System.out.println(current_list.get(i));
	}
    }
}