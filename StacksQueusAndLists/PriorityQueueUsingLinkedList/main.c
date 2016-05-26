/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 1:20 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct node {
    int data;
    struct node *next;
    
};
struct queue{
    struct node *front,*rear;
};
void insert(struct node **front,int val){
    struct node *newnode,*cur,*prev;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    cur=*front;
    if(*front==NULL){
        newnode->next=NULL;
        *front=newnode;
    }
    else{
        while(cur!=NULL && (cur->data) < (newnode->data) ){
           prev=cur;
           cur=cur->next;
        }
        if(*front==cur){
            newnode->next=cur;
            *front=newnode;
        }
        else {
            newnode->next = prev->next;
            prev->next=newnode;
            
        }
    }
}
int removeq(struct node **p){
    int val=0;
    struct node *cur ;
    cur =*p;
    if(*p==NULL){
        printf("Queue empty");
        return 0;
    }
    else{
        val=cur->data;
        *p= cur->next;
        if(*p==NULL){
            printf("Last Element also removed");
        }
        free(cur);
        return val;
    }
}
int main(int argc, char** argv) {
    struct node *p;
    insert(&p,1);
    insert(&p,2);
    printf("%d",removeq(&p));
    return (EXIT_SUCCESS);
}

