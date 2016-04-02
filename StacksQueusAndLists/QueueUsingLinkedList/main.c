/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 12:30 AM
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
struct queue {
    struct node *rear,*front;
    
};

void insert(struct queue *p ,int val){
    struct node * newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(p->rear==NULL){
        p->front=p->rear=newnode;
        
    }
    else {
        p->rear->next = newnode;
        p->rear = newnode;
        
    }
}
int removeq(struct queue *p){
    int val;
    struct node *cur =NULL;
    if(p->front ==NULL){
        printf("Queue is empty");
    }
    else {
        val = p->front->data;
        cur=p->front;
        p->front=p->front->next;
        if(p->front==NULL){
            p->rear=NULL;
        }
        free (cur);
        return val;
    }
}
int main(int argc, char** argv) {
    struct queue s;
    int val,ch;
    s.front=s.rear=NULL;
    insert(&s,7);
    insert(&s,8);
    printf("%d",removeq(&s));
    return (EXIT_SUCCESS);
}

