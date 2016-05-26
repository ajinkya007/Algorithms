/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 1:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * only one disk can be removed at a time
 * larger one cannot be placed on the smaller disk
 * only one auxiliary stand can be used
 * Total no of shifts for n disks is (2^n)-1
 */
int tower (int n,char s,char a,char t){
    if(n==1){
        printf("Shift %d from %c to %c \n",n,s,t);
        return 1;
    }
    else {
        int x = tower(n-1,s,t,a);
        printf("Shift %d from %c to %c \n ",n,s,t);
        int y= tower(n-1,a,s,t);
        return (x +y +1);
    }
}
int main(int argc, char** argv) {
    int n=5;
    char s ='s',a='a',t='t';
    printf("\n%d%\n",tower(3,s,a,t));
    return (EXIT_SUCCESS);
}

