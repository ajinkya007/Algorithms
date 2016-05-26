/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 6, 2014, 6:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct node {
    int data;
    struct node * prev , * next;
};
void addFirst(struct node **front ,int val)
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc (sizeof(struct node));
    newnode->data=val;
    if(*front==NULL){
        newnode->prev =NULL;
        newnode->next =NULL;
        *front =newnode;
    }
    else {
        (*front)->prev = newnode;
        newnode->next =(*front);
        *front =newnode;
        newnode->prev =NULL;
        
    }
}
void add(struct node **front ,int val){
    struct node * newnode,*temp;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(*front==NULL){
        *front = newnode;
        newnode->prev =NULL;
        newnode->next = NULL;
    }
    else {
        temp = *front;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        newnode->prev =temp;
    }
    
}
void display(struct node **front){
    struct node *cur;
    cur =*front;
    while(cur!=NULL){
        printf("%d",cur->data);
        cur=cur->next;
    }
}
void dispplayRev(struct node **front){
    struct node *cur;
    cur=*front;
    while (cur->next!=NULL){
        cur=cur->next;
    }
    while(cur!=NULL){
        printf("%d",cur->data);
        cur=cur->prev;
    }
}
void delete(struct node **front,int val){
    struct node *cur;
    cur =*front;
    if (cur->data==val && cur == *front){
        *front =cur->next;
        free(cur);
    }
    else{
        while (cur!=NULL && cur->data!=val){
            cur=cur->next;
        }
        (cur->prev)->next =cur ->next;
        (cur->next)->prev = cur->prev;
    }
}
int main(int argc, char** argv) {
    struct node *p =NULL;
    addFirst(&p,1);
    addFirst(&p,2);
    addFirst(&p,3);
    addFirst(&p,4);
    add(&p,5);
    add(&p,6);
    display(&p);
    delete(&p,3);
    display(&p);
    return (EXIT_SUCCESS);
}

