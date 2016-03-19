/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 6:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 * 
 */
struct queue{
    int arr[max];
    int rear ,front;
};
void insertq(struct queue * p , int val){
    if (p -> rear == max -1)
        printf("Queue is full");
    else p->arr[++p->rear]= val;
}
int removeq(struct queue *p){
    if(p->rear == p->front){
        printf("Queue is empty");
        return 0;
    }
    else return p->arr[++p->front];
}
int main(int argc, char** argv) {
    struct queue q;
    int x;
    q.rear = -1;
    q.front =-1;
    insertq(&q,9);
    insertq(&q,10);
    printf("%d",x=removeq(&q));
    return (EXIT_SUCCESS);
}

