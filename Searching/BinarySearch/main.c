/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 4:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define size 10
/*
 *Best case if the value to be searched is located at the centre.O(1).
 * worst case O(log n )
 * Average case O(log n) 
 */
int bsearchNonRecur(int a[],int val,int low,int high){
    while(low<=high){
        int mid = (low +high )/2;
        if(a[mid]==val)
            return 1;
        else if (a[mid]<val)
            low =mid +1;
        else high =mid -1;
        
    }
}
int bsearchRecur(int a[],int val,int low,int high){
    if (low>high)
        return 0;
    else {
        int mid = (high +low)/2;
        if (a[mid]== val)
            return 1;
        else if(a[mid] > val)
            high =mid-1;
        else low= mid +1;
        return bsearchRecur(a,val,low,high);
    }
}
int main(int argc, char** argv) {
    int a[size],n,val,i;
    printf("\n Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched \n");
    scanf("%d",&val);
    int c = bsearchRecur(a,val,0,n);
    int d = bsearchNonRecur(a,val,0,n);
    printf("Element is found at position %d \t %d ", c ,d);
    
    return (EXIT_SUCCESS);
}

