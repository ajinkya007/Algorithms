/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 9:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
/*
 * 
 */
void add(struct node **front,int val){
    struct node *newnode,*temp;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data= val;
    if(*front==NULL){
        newnode->next=newnode;
        *front=newnode;
        
    }
    else{
        
        newnode->next=(*front)->next;
        (*front)->next=newnode;
        *front=newnode;
    }
    
}
int removeq(struct node **front){
    struct node *cur;
    if(*front==NULL){
        printf("Queue IS Empty");
        return 0;
    }
    else {
        cur=(*front)->next;
        int val=cur->data;
        (*front)->next=cur->next;
        if(cur==(*front)->next){
            *front=NULL;
            printf("All elements removed");
        }
        free (cur);
        return val;
  
    }
    }
int main(int argc, char** argv) {
    struct node *cq=NULL;
    add(&cq,10);
    add(&cq,12);
    printf("%d",removeq(&cq));
    return (EXIT_SUCCESS);
}

