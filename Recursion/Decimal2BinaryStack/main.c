/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 6, 2014, 11:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define size 10
/*
 * 
 */
struct stack {
    int top;
    int arr[size];
};
int isFull(struct stack *p){
    return (p->top ==size -1);
}

int isEmpty(struct stack *p){
    return (p->top== -1);
}
void push(struct stack *p, int val){
    if(p->top== size-1)
        printf("Stack Overflow");
    else 
        p ->arr[++p->top]= val;
}

int pop (struct stack *p){
    if (p->top == -1){
        printf("Stack Underflow");
        return 0;
    }
    else return p->arr[p->top--];
}

int main(int argc, char** argv) {
    int v=0,n=18;
    struct stack s;
    s.top=-1;
    while(n!=0){
        push(&s,n%2);
        n/=2;
    }
    while(!isEmpty(&s)){
        v=pop(&s);
        printf("%d",v);
    }
    return (EXIT_SUCCESS);
}

