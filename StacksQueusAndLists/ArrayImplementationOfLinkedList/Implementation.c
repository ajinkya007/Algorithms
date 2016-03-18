/* 
 * File:   Implementation.c
 * Author: Ajinkya Wavare
 *
 * Created on September 7, 2014, 10:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define size 10
/*
 * 
 */
struct node {
    int data;
    int next;
}a[size];
int first =-1,aval=0;
void init (){
    int i;
    for(i=0;i<size;i++){
        a[i].next=i+1;
        a[size-1].next=-1;
    }
}
int alloc(){
    int p=aval;
    if(p!=-1)
        aval=a[p].next;
    return p;
}
void add(int v){
    int p;
    p = alloc();
    if(p==-1){
        printf("Full");
    }
    a[p].data=v;
    a[p].next=-1;
    if(first==-1)
        first=p;
    else {
        int t =first;
        while (a[t].next!=-1){
            t=a[t].next;
        }
        a[t].next=p;
    }
}
void display(){
    int t=first;
    while(t!=-1){
        printf("%d \t",a[t].data);
        t=a[t].next;
    }
}
void del(int v){
    int t=first,prev;
    while(t!=-1){
        if(a[t].data==v)
            break;
        prev=t;
        t=a[t].next;
    }
    if(t==-1){
        printf("Number does not exist");
    }
    else {
        if (t==first)
            first=a[t].next;
        else
            a[prev].next=a[t].next;
        a[t].next=aval;
        aval=t;
    }
}
int main(int argc, char** argv) {
    init();
    add(10);
    add(20);
    display();
    del(20);
    display(20);
    return (EXIT_SUCCESS);
}

