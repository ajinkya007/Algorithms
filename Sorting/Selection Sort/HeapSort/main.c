/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:16 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *Improved version of the selection sort in which largest element is selected and exchanged with the
 * last element of the unsorted list.
 * two procedures:-
 * 1.construction:
 * array elements are arranged as descending heap.
 * every node is considered as a heap and the construction begins from n/2 till 0 th location
 * 
 * 2.Reconstruction:
 * max element at the root is swapped with the last location.
 * after swapping if the last element which is shifted at the  root  does not fit at the location  then a suitable value is searched from either the right or the left child.
 * the procedure goes on until last element find its suitable place.
 * 
 * 3.the procedure is continued till only one element is left in the array
 * 
 *  Analysis in all the cases is O(n log n).
 * 
 */
void construct (int a[],int i,int n){
    int temp,child;
    for(temp=a[i];(2*i+1)<n;i=child){
        child = 2*i+1;
        if(a[child]<a[child+1] && child<n-1)
            child++;
        if(temp<a[child])
            a[i]=a[child];
        else break;
        
    }
    a[i]=temp;
}
void heapsort (int a[],int n){
    int i,j,temp;
    //construction of heap
    for(i=n/2;i>=0;i--)
        construct(a,i,n);
    
    //reconstruction of heap
    for(i=n-1;i>0;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        construct(a,0,i);
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
    heapsort(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

