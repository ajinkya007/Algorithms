/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 8, 2014, 9:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 * Implemented with the help of queue
 * level order traversing
 */
void bfs (int adj[][],int start){
    int i;
    int visited[max]={0};
    int q[30],first=-1,last=-1;
    visited[start]=1;
    q[++last]=start;
    while(first!=last){
        start=q[++first];
        printf("%d",start +1);
        for(i=0;i<max;i++)
            if (adj[start][i]!=0 && visited[start] ==0){
                q[++last]=i;
                visited[i]=1;
            }
    }
}
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

