/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 5:31 PM
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
    struct stack s;
    s.top=-1;
    int i,c;
    char str[20];
    scanf("%s",str);
    printf("%s",str);
    
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            push(&s,str[i]);
        }
        if(str[i]==')')
            c=pop(&s);        
    }
    if(s.top==-1)
        printf("Valid Expression");
    else printf("Invalid Expression");
    
    return (EXIT_SUCCESS);
}

