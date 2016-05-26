/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 4:55 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * In bubble sort largest value is settled at the last location at the first place then the second largest in the second pass.
 * whereas in the shaker sort the largest and the smallest value get settled at the last and first position at the first pass itself.
 * the procedure is continued till the middle is reached.
 * 
 * Average case analysis same as that of the bubble sort but the constant here is further less.
 */
void shaker (int a[],int n){
    int i,j,x,temp,flag=1;
    for(i =0;flag;i++){
        flag =0;
        for(j =i ;j<n-1-i;j++)
            if (a[j]>a[j+1]){
                temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag =1;
            }
        if(flag){
            flag=0;
            for(j=n-2-i;j>=i+1;j--){
                if(a[j-1]>a[j]){
                    temp =a[j];
                    a[j]=a[j-1];
                    a[j-1]=temp;
                    flag =1;
             
                }
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
    shaker(a,n);
    for(i=0;i<n;i++){
        printf("%d \t",a[i]);
    }
    
    return (EXIT_SUCCESS);
}

