/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 6:18 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * two arrays exist at the lhs of element to be settled and the rhs of element.
 * lhs is sorted and rhs is unnsorted.
 * if element to be settled is lesser than the existing sorted array then  it is inserted on the rhs
 * start the procedure from second position.
 * 
 * best case O(n).
 * worst and avg case O(n^2)
 */

void insertion(int a[],int n){
    int i,j,y;
    for(i =1;i<n;i++){
        y=a[i];
        for(j=i;j>0&&y <a[j-1];j--)
            a[j]=a[j-1];
        a[j]=y;
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
    insertion(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    
    return (EXIT_SUCCESS);
}

