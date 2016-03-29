/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 6, 2014, 6:09 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *If address is going to change then pass **front etc if not then the work can be done by even passing the single pointer. 
 */

struct node{
    int data;
    struct node *next;
};
void addFirst(struct node **front,int val){
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->next=*front;
    newnode->data=val;
    *front=newnode;
}
void add(struct node **front,int val){
    struct node * newnode,* temp;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(*front==NULL){
        *front=newnode;
    }
    else {
        temp=*front;
        while (temp!=NULL){
            temp=temp->next;
            
        }
        temp->next=newnode;
    }
}
void display(struct node **front){
    struct node *cur;
    cur=*front;
    while(cur!=NULL){
        printf("%d",cur->data);
        cur=cur->next;
    }
}
void display1(struct node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
void del(struct node **front,int val){
    struct node *cur ,*prev;;
    cur=prev=*front;
    while(cur->data!=val&&cur!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL){
        printf("Value Does nOt exist");
    }
    else if (prev==cur){
        *front=cur->next;
        free (cur);
    }
    else {
        prev->next=cur->next;
        free(cur);
    }
}
int count (struct node **front){
    int c=0;
    struct node *cur ;
    cur = *front;
    while(cur!=NULL){
        ++c;
        cur=cur->next;
        
    }
    return c;
}
int count1 (struct node *p){
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void copy(struct node **front1,struct node **front2){
    struct node *newnode,*cur1,*cur2;
    cur1=*front1;
    while(cur1!=NULL){
        newnode= (struct node *)malloc(sizeof(struct node));
        newnode->data=cur1->data;
        if(*front2==NULL){
            *front2=newnode;
            cur2=*front2;
        }
        else {
            cur2->next=newnode;
            cur2=newnode;
        }
        newnode->next=NULL;
        cur1=cur1->next;
    }
}
void search (struct node *p,int val){
    int flag =0;
    while(p!=NULL){
        if(p->data==val){
            flag =1;
            break;
        }
        else p=p->next;
        
    }
    if(flag ==1){
        printf("Value found");
    }
}
void reverse(struct node **front){
    struct node *prev,*temp,*t;
    prev=NULL;
    temp=*front;
    while(temp!=NULL){
        t= temp->next;
        temp->next=prev;
        prev =temp;
        temp=t;
    }
    *front=prev;
    
}// important and twisty

/*functions fot intersection and uniion of linked lists
use of two while loops o find the common elements etc 
*/

void destroy(struct node * front){
    struct node *temp;
    temp = front;
    while(temp!=NULL){
        front = temp->next;
        free (temp);
        temp =front;
    }
    printf("Destroyed");
}
int main(int argc, char** argv) {
    struct node *p =NULL;
    addFirst(&p,1);
    addFirst(&p,2);
    //add(&p,3);
    //add(&p,4);
    //int c = count1(p);
    //int c1 =count(&p);
    //printf("%d\n%d",c,c1);
    display(&p);
    destroy(p);
    return (EXIT_SUCCESS);
}

