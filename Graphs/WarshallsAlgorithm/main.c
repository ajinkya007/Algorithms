/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 8, 2014, 9:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 * the complexity is only O (n^3) whereas for the other algorithm it is O(n^4)
 */
void warshall(int g[max][max],int tc[max][max]){
    int i,j,k;
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
            tc[i][j]=g[i][j];
    
    for(i=0;i<max;i++)
        for(j=0;j<max;j++)
            for(k=0;k<max;k++)
            {
                if(tc[i][j]==0)
                    if(tc[i][k]==1 && tc[k][i]==1)
                        tc[i][j]= 1 ;
            }
            tc[i][j]=g[i][j];
    
    
}
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

