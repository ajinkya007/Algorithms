/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 1:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * in this program we try to find all the ways to place n queen in nXn chessboard.we represent the problem in an array 'x'.x[i] represents the column of the the ith queen on the ith row.
 * when we place the queen on the kth row the following conditions need to be satisfied.
 * 1.no two queens can be on the same row. 
 * i!=k
 * 2.no two queens can be on the same column.
 * ie. a[i]!=a[k]
 * 3.No two queens can be placed at the diagonal
 * ie. |a-k|=|a[i]-a[K]|
 * AddQueen() is a function that tests whether a queen can be placed at the a[k]th column at the kth  row by checking the abbove conditions
 * 
 */
int addQueen(int Q[],int k){
    int i;
    for(i=0;i<k;i++){
        if(Q[i]==Q[k]||(abs(Q[i]-Q[k])==abs(i-k)))
            return 0;
        
    }
    return 1;
}
void NQueen(int Q[],int k,int n){
    int i,j;
    for(i=0;i<n;i++){
        Q[k]=i;
        if(addQueen(Q,k)){
            if(k==n-1){
                for(j=0;j<n;j++){
                    printf("%d",Q[j]);
                    printf("\n");
                }
            }
            else{
                NQueen(Q,k+1,n);
            }
        }
    }
}
int main() {
    int n,Q[20]={0},i;
    printf("Enter the no of Queens");
    scanf("%d",&n);
    printf("\n %d\n",n);
    NQueen(Q,0,n);
    return (EXIT_SUCCESS);
}

