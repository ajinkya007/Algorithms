/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 5:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define size 10

/*
 * 
 */
 //Define the structure
struct stack {
    int top;
    int arr[size];
};
//Check if the stack is full
int isFull(struct stack *p){
    return (p->top ==size -1);
}
//Check if the stack is empty
int isEmpty(struct stack *p){
    return (p->top== -1);
}
//Push on top of the stack
void push(struct stack *p, int val){
    if(p->top== size-1)
        printf("Stack Overflow");
    else 
        p ->arr[++p->top]= val;
}
//Remove from top of the stack
int pop (struct stack *p){
    if (p->top == -1){
        printf("Stack Underflow");
        return 0;
    }
    else return p->arr[p->top--];
}
int main(int argc, char** argv) {
    struct stack s;
    s.top=-1;
    push(&s,7);
    push(&s,8);
    printf("%d \t",pop(&s));
    return (EXIT_SUCCESS);
}

