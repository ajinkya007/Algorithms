/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define size 50
/*
 * List all the elements in the list are within the range of the array .
 * create a counter array to find the elements which are repeated and store it in the counter arrray.
 * arrange the elements in the array depending on the counter array/
 * 
 * maximum iterations is 2n.all are stored in the same bucket then the inner loop iterates n times
 * 
 * analysis for all the cases is O(n)
 * 
 */
void bucket(int a[],int n){
    int i,j,count[size]={0};
    for(i=0;i<n;i++){
        count[a[i]]++;
    }
    for(i=0,j=0;i<n;i++){
        while(count[i]-- > 0)
            a[j++]=i;
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
    bucket(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

