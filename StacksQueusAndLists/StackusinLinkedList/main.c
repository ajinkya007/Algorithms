/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 1:10 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct stack{
    int data;
    struct stack *next;
};
void push( struct stack **front,int val){
    struct stack * newnode;
    newnode= (struct stack *)malloc(sizeof(struct stack));
    newnode->next = *front;
    *front=newnode;
    newnode->data=val;
}
int pop(struct stack **front){
    int c=0;
    struct stack *cur;
    cur =*front;
    if(*front==NULL)
        printf("Stack Empty");
    else{
        c =cur->data;
        *front = cur->next;
        free (cur);
    }
    return c;
}
int main(int argc, char** argv) {

    struct stack *s=NULL;
    push(&s,1);
    push(&s,2);
    printf("%d",pop(&s));
    return (EXIT_SUCCESS);
}

