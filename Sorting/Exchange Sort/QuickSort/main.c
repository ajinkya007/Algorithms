/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 5:15 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * A pivot is taken at random,all the elements of the left must be smaller than it and all on right 
 * must be greater than the pivot
 * then the elements on the left and right side of the pivot are sorted in similar way.
 * usually pivot is taken to be in the middle.
 * its the fastest type of sorting.
 * the avg case analysis is O(log n).
 * 
 * Here a function partition is used.
 * 1.Take the first value.
 * 2.compare the elements from the second location.
 * 3.if the current element is greater than pivot then store location in i;
 * start to compare last location .if the current element is smaller than the pivot then stop.store its location in j.
 * 4.if i is less than j then swap i th and the j th element and continue 2 and 3.
 * if not then swap the pivot with the jth element.
 * thus one pass is complete.
 * 5.divide the array into two left side of the pivot and the right side.
 * solve using the same concept.
 * 
 * Worst case analysis O(n^2)
 * best and average case 0(n log n)
 * 
 */
int partition (int a[],int low,int high){
    int i,j,temp;
    i = low+1;
    j = high;
    int x = a[low];
    while(i<j){
        while(a[i]<x && low<=high)
            i++;
        while(a[j]>x)
            j--;
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else{
            a[low]=a[j];
            a[j]=x;
            break;
        }
    }
    return j;
}

void quickRecur(int a[],int low,int high){
    int j;
    if (low <high){
        j=partition(a,low,high);
        quickRecur(a,low,j-1);
        quickRecur(a,j+1,high);
    }
}

void quickNonRecur(int a[],int low,int high){
    struct {
        int lo,up;
    }stack[20],item;
    int top = -1,pos;
    top ++;
    stack[top].lo=low;
    stack[top].up=high;
    
    while(top!=-1){
        low =stack[top].lo;
        high =stack[top].up;
        top --;
        if(low<high){
            pos =partition(a,low,high);
            top++;
            stack[top].lo=low;
            stack[top].up=pos-1;
            top++;
            stack[top].lo=pos+1;
            stack[top].up=high;
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
    quickRecur(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    quickNonRecur(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    return (EXIT_SUCCESS);
}

