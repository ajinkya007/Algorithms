/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 6:30 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Shell Sort creates a sub list with in interval.
 * the interval is taken as half the number of elements.
 * elements with the same interval are connected and created as a sub list.
 * each sub list is sorted with insertion sort.
 * the interval is reduced into half of the current and same procedure is followed until interval becomes 0.
 * 
 * 
 *Best case and average case O(n log n )
 * Worst case O(n^2)
 */
void shell(int a[],int n){
    int i, j, inc;
    for (inc = n/2; inc >=1; inc/=2){
        for (i =inc; i < n; i++){
            int y  = a[i];
            for (j = i; j >0 && y <a[j-inc]; j--)
                a[j]=a[j-1];
            a[j]=y;
            
        }
    }    
  
}
int main(int argc, char** argv) {
    int a[10],n,i;
    printf("\n Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shell(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

