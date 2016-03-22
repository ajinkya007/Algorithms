/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 6, 2014, 8:00 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Linear linked lists for inserting n elements use n(n-1)/2 iterations .
 * to avoid this we make use of a circular linked lists .
 * for inserting n elements only n iterations.
 */
struct node {
    int data;
    struct node *next;
};

void add(struct node **front,int val){
    struct node *newnode,*temp;
    newnode = (struct node *)malloc (sizeof(struct node));
    newnode->data=val;
    if(*front==NULL){
        newnode->next=*front;
        *front=newnode;
        
    }
    else {
        
        newnode->next =(*front)->next;
        (*front)->next= newnode;
        *front=newnode;
    }
}
void display (struct node **p){
    struct node *temp =NULL;
    temp = (*p)->next;
    do{
        printf("%d",temp->data);
        temp=temp->next;
    }while(temp!=(*p)->next);
}
void delete (struct node **front,int val){
    int x =0;
    struct node *prev,*temp;
    prev =*front;
    temp = (*front)->next;
    do {
        if(temp->data==val){
            int x=1;
            break;
        }
        prev =temp;
        temp=temp->next;
        
    }while (temp!=(*front)->next);
    if (x){
        prev->next = temp->next;
        if(temp==*front){
            *front=prev; //last element
        }
        if (temp==temp->next)
            *front=NULL; //only one element in list
            free (temp);
    }
    else printf("Data Not found");
}
int main(int argc, char** argv) {
    struct node * p;
    p=NULL;
    add(&p,1);
    add(&p,2);
    add(&p,3);
    display(&p);
    return (EXIT_SUCCESS);
}

