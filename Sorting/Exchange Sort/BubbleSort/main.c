/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 4:27 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Number of passes = n-1
 * n-i comparison for the ith pass.
 * the best case,worst case and the average case analysis is the same.
 * O(n^2)
 * 
 * on the first pass itself the largest element is settled on the last position
 * on the ith iteration the ith largest element is settled at the ith last position.
 */
void bubble(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
/*
 * Modified Bubble sort
 * In the above version even after the array is sorted the iteration continues.
 * if there is no swapping in a pass it concludes that the array is sorted and the process is terminated.
 * It is done with the help of a flag variable
 * 
 * Best case occurs when it is sorted .
 * after the first iteration it does gets terminated.
 * whereas for average and worst case it is same.
 * O(n^2) but in the average case the value of the constant with it decreases. 
 */

void modifyBubble(int a[],int n){
    int i,j,temp;
    int flag=1;
    for(i=1;i<n && flag;i++){
        flag = 0;
        for(j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                flag =1;
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
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
    bubble(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    printf("\n");
    modifyBubble(a,n);
     for(i=0;i<n;i++){
        printf("%d \t ",a[i]);
    }
   
    return (EXIT_SUCCESS);
}

