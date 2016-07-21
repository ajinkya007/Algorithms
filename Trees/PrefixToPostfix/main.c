/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 8, 2014, 1:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
char * prepost (char *pre ,char *post){
    char *p;
    if(isalpha(*pre)){
        strncat(post,pre,1);
        return pre;
    }
    else {
        p=prepost(pre+1,post);
        p=prepost(p+1,post);
        strncat(post,pre,1);
        return p;
    }
}
int main(int argc, char** argv) {
    char a[20],post[20];
    printf("Enter the prefix Operand :");
    scanf("%s",a);
    prepost(a,post);
    printf("%s",post);
    return (EXIT_SUCCESS);
}

