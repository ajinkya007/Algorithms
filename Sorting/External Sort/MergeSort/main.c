/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:16 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  Array is divided into half until there is only one element left in the array.
 * then each sub sequenet array are merged and formed as an array of size 2.
 * arrays are merged again to form an array of size 4
 * procedure continued tillarray becomes same as the original size.
 * 
 * odd 
 * 1st two 
 * then 1st three 
 *  
 * Analysis for all cases is O(n log n)
 */
void merge(int a[],int l1,int u1,int l2,int u2){
    int i,j,n=0,temp[50];
    i=l1;
    j=l2;
    while(i<=u1 && j<= u2)
        temp[n++]=a[i]<a[j]?a[i++]:a[j++];
    while(i<=u1)
        temp[n++]=a[i++];
    while(j<=u2)
        temp[n++]=a[j++];
    n=0;
    for(i=l1;i<=u2;i++)
        a[i]=temp[n++];
     
}
void mergesort(int a,int low,int high){
    int mid;
    if(low<high){
        mid =(low + high )/2;
        mergesort(a,low,mid);
        mergesort(a,mid +1,high);
        merge(a,low,mid,mid+1,high);
        
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
    mergesort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

