/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 1:43 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Implementation of Circular Linked List
 */
struct node{
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
void display (struct node *p){
    struct node *temp;
    temp = p->next;
    do{
        printf("%d",temp->data);
        temp=temp->next;
    }while(temp!=p->next);
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

void josephus(struct node **p){
    struct node *temp,*prev;
    int i;
    temp = *p;
    while(*p!=(*p)->next){
        int n = random()%50;
        temp=*p;
        for(i=1;i<n;i++){
            prev=temp;
            temp=temp->next;
        }
        printf("%d removed ", temp->data);
        prev->next=temp->next;
        free(temp);
        *p=prev->next;
    }
    printf("%d winner ",(*p)->data);
}
int main(int argc, char** argv) {
    struct node *front=NULL;
    add(&front,1);
    add(&front,3);
    add(&front,5);
    josephus(&front);
    return (EXIT_SUCCESS);
}

