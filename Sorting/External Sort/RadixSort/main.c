/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:17 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * We create a set of buckets and distribute the elements based on the key digit;
 * after distributing we collect them from the first bucket .
 * the same procedure is repeated for further key digits
 * 
 * each key is looked at m number of times where m is the maximum nummber of digits .
 * 
 * analysis for all cases is O(m *n )
 * m no of digits
 */
void radix(int a[],int n){
    int i,exp=1,max=0;
    for(i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    int * t =(int * )malloc (n * sizeof(int));
    int * b =(int * )malloc (10 * sizeof(int));
    while(max/exp >0){
        for(i =0;i<n;i++)
            b[a[i]/exp%10]++;
        
        for(i =1;i<=10;i++)
            b[i]+=b[i-1];
        
        for(i =n-1;i>=0;i--)
            t[--b[a[i]/exp%10]]=a[i];
        
        for(i =0;i<n;i++)
            a[i]=t[i];
        exp=exp*10;
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
    radix(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
     printf("%\n");
    

    return (EXIT_SUCCESS);
}

