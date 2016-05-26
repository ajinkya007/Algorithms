/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 6:54 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * The smallest element at the ith location is settled where i varies from 0 to n-1.
 * a search is made to locate the smallest key from the i +1 location to n.
 * smallest location is interchanged with i th location.
 * iterate from i to n-1
 * 
 * total no of interchanges is n-1
 * and the avg best and worst case scenario is O(n^2).
 */
void selection (int a[],int n){
    int i,j,temp,pos;
    for(i =0;i<n-1;i++){
        pos =i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[pos])
                pos =j;
        }
        temp = a[pos];
        a[pos]=a[i];
        a[i]=temp;
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
    selection(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

