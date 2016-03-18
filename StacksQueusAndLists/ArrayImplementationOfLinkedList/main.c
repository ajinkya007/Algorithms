/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:19 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct node {
    int data,next;
};
struct node n[10];
int avail=0;
void init(){
    int i;
    for(i-=0;i<10;i++){
        n[i].next=i+1;
    }
    n[9].next=-1;
}
void insert(int p,int val){
    if(avail==-1){
        printf("Linked List Full");
    }
    else {
        int q =avail;
        n[q].data=val;
        avail=n[q].next;
        n[q].next=n[p].next;
        n[p].next=q;
    }
}
int rem(int p){
    int v,q;
    if(p==-1||n[p].next==-1){
        printf("Cannot remove");
        exit(0);
    }
    else {
        q=n[p].next;
        v=n[q].data;
        n[p].next=n[q].next;
        avail=q;
        return v;
    }
}
int main(int argc, char** argv) {
    
    int ch,pos,val;
    init();
    do{
        printf("Enter Your Choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the position and value");
                scanf("%d %d",pos ,val);
                insert(pos,val);
                break;
         
            case 2:
                printf("Enter the position after which the value is to be removed");
                scanf("%d",&pos);
                printf("The value removed %d ", rem(pos));
                break;
        }
    }while(ch==1||ch==2);
    return (EXIT_SUCCESS);
}

