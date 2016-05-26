/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 9:56 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct node {
    int data;
    struct node * next;
};
void push(struct node **front,int val){
    struct node *newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(*front==NULL){
        newnode->next=newnode;
        *front=newnode;
    }
    else{
        newnode->next =(*front)->next;
        (*front)->next=newnode;
        
    }
}
int pop(struct node **front){
    int val=0;
    struct node *cur;
    if(*front==NULL){
        printf("Stack Empty");
        return 0;
    }
    else {
        cur=(*front)->next;
        val=cur->data;
        (*front)->next=cur->next;
        if(*front==cur){
            *front=NULL;
        }
        free (cur);
        return val;
    }
}
int main(int argc, char** argv) {
    struct node *p =NULL;
    push(&p,10);
    push(&p,12);
    printf("%d",pop(&p));
    printf("%d",pop(&p));
    return (EXIT_SUCCESS);
}

