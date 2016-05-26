/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 6:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 * 
 */
struct cqueue{
    int arr[max];
    int rear,front;
    
};
int isEmpty(struct cqueue *p){
    if(p->front == p->rear){
        printf("Circular queue Empty.");
        return 1;
    }
    else return 0;
}
void insertCq(struct cqueue *p,int val){
    int t ;
    t =(p->rear +1)% max;
    if(t==p->front){
        printf("Overflow");
    }
    else {
        p->rear =t;
        p->arr[p->rear]=val;
    }
}

int removeCq(struct cqueue *p){
    if(isEmpty(p))
    {
        printf("Underflow");
        return 0;
    }
    else {
        p->front=(p->front+1)% max;
        return p->arr[p->front];
    }
}
/*
struct cqueueCounter{
    int arr[max];
    int rear,front,counter;
};
void add(struct cqueueCounter *q,int val){
    if(q->counter==max)
        printf("Queue Full");
    else {
        q->counter++;
        q->rear=(q->rear +1)%max;
        q->arr[q->rear]=val;
    }
}
int removeCqC(struct cqueueCounter *q){
    if(q->counter==0){
        printf("Queue Empty");
        
    }
    else {
        q->counter--;
        q->front=(q->front +1)%max;
        return q->arr[q->front];
    }
}
void display(struct cqueueCounter q){
    while(q.counter!=0){
        printf("%d",removeCqC(&q));
        
    }
}*/
int main(int argc, char** argv) {
    struct cqueue q;
    q.rear=q.front=0;
    insertCq(&q,8);
    insertCq(&q,80);
    insertCq(&q,81);
    insertCq(&q,28);
    int v= removeCq(&q);
    int v1= removeCq(&q);
    
    printf("%d\t %d \t%d \t %d",v ,v1,q.front,q.rear);
   /* 
    struct cqueueCounter q1;
    q1.rear=q1.front=q1.counter=0;
    add(&q1,1);
    add(&q1,2);
    int v2=removeCqC(&q1);
    display(q1);
    */
    return (EXIT_SUCCESS);
}

