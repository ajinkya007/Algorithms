/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 12:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
 //Recursive function for factorial
int fact(int n){
//Test for the base condition and the recursive condition
    if (n==0)
        return 1;
    else 
        return n*fact(n-1);
}
int main(int argc, char** argv) {
    int x=5;
    printf("%d",fact(5));
    return (EXIT_SUCCESS);
}

