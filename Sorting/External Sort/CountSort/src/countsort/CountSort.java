/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package countsort;
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/**
 *
 * @author Ajinkya Wavare
 */
public class CountSort {

    /**
     * @param args the command line arguments
     */
        public static void countSort(int []a,int min,int max){
        int[] count= new int[max - min + 1];
	for(int number : a){
		count[number - min]++;
	}
         for(int n =1;n < max;n++)
            count[n]=count[n] + count[n -1];
	    printArray(count);
    
	int z= 0;
	for(int i= min;i <= max;i++){
		while(count[i - min] > 0){
			a[z]= i;
			z++;
			count[i - min]--;
		}
	}
        printArray(count);
    }
     private static void printArray(int[] ar) {
      for(int n: ar){
         System.out.print(n+" ");
      }
        System.out.println("");
   }

    public static void main(String[] args) {
        // TODO code application logic here
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        int min=0,max=100;
        String s[]=new String[n];
        for(int i=0;i<n;i++){
            a[i]= sc.nextInt();
            s[i]=sc.next();
        }
        countSort(a,min,max);
        
    
    }
    
}
