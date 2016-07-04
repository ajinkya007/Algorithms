/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 8, 2014, 2:22 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * 
 */
char *preinfix(char * pre,char * in){
    char *p;
    if(isalpha(*pre)){
        strncat(in,pre,1);
        return pre;
    }
    else {
        strncat (in ,'(',1);
        p= preinfix(pre +1,in);
        p=strcat(pre+1,in);
        p = strcat(in ,')');
        return p;
    }
}
int main(int argc, char** argv) {
    char a[20],in[20];
    printf("Enter the prefix Operand :");
    scanf("%s",a);
    preinfix(a,in);
    printf("%s",in);
    
    return 0;
}

