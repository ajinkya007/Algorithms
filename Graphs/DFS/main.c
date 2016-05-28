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
 * 
 */
void dfs(int adj[max][max],int visited [],int start){
    int i;
    printf("%c",start +64);
    visited[start]=1;
    for(i=0;i<max;i++)
        if(adj[start][i]==1 && visited == 0)
            dfs(adj,visited,i);
}
int main(int argc, char** argv) {
    int visited [max]= {0};
    return (EXIT_SUCCESS);
}

