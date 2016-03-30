/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 6, 2014, 11:54 PM
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
    char a[20];
    stack s;
    s.top =-1;
    int v=1;
    printf("Enter the expression");
    scanf("%s",a);
    for(int i=00;a[i];i++){
        if(a[i]=='(')
            push(&s,')');
        if(a[i]=='{')
            push(&s,'}');
        if(a[i]=='[')
            push(&s,'}');
        if(a[i]==']'||a[i]=='}'||a[i]==')'){
            if(a[i]!=pop(&s))
            {
                v=0;
                break;
            }
        }
    }
    if(v==0||s.top!=-1)
        printf("Unbalanced");
    else  printf("Balanced");
    return (EXIT_SUCCESS);
}

