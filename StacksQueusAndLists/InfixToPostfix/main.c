/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 5:55 PM
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
int preced(char op);
int higher(char op1,char op2){
    int r1= preced(op1);
    int r2= preced(op2);
    if (r2>r2)
        return 1;
    else return 0;
   
}
int preced(char op)
{
    int r;
    switch(op){
        case '(':
            r=0;
            break;
        case '+':
        case '-':
            r=1;
            break;
        case '*':
        case '/':
        case '%':
            r=2;
            break;
        case '^':
            r=3;
            break;
        case ')':
            r=4;
            break;
        
    }
    return r;
}
int main() {
    struct stack s;
    char str[30],post[30];
    int i,j=0;
    s.top=-1;
    printf("Enter the infix expression: ");
    scanf("%s",str);
    for( i=0;str[i]!='\0';i++){
        if(isalpha(str[i])){
            post[j++]=str[i];
        }
        else if(str[i]!=')'){
            while(s.top!=-1 && higher(str[i],pop(&s)) && str[i]!= '()' && pop(&s)!= '^' && str[i]!='^'){
                post[j++]=pop(&s);
            }
            push(&s,str[i]);
        }
        else {
            char ch;
            while((ch=pop(&s))!= '('){
                post[j++]= ch;
            }
        }
    }
    while(s.top!= -1){
        post[j++]= pop (&s);
       
    }
    post[j]='\0';
    printf("%s",post);
    return (EXIT_SUCCESS);
}

