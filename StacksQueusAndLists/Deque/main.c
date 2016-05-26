/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on September 5, 2014, 6:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 * 
 */
struct deque {
    int arr[max];
    int rearleft,rearright,frontleft,frontright;
};
void insertleft(struct deque * p, int v){
    if(p->rearleft+1 == p->rearright){
        printf("Overflow");
    }
    else p->arr[++p->rearleft] = v;
}
void insertright(struct deque * p, int v){
        if(p->rearleft+1 == p->rearright){
        printf("Overflow");
    }
    else p->arr[--p->rearright] = v;
    
}

int removeleft(struct deque *p){
    if(p->frontleft == p->rearleft){
        printf("Underflow");
        return 0;
    }
    else return  p->arr[++p->frontleft];
}
int removeright(struct deque *p){
    if(p->frontright == p->rearright){
        printf("Underflow");
        return 0;
    }
    else return  p->arr[--p->frontright];
}

int main(int argc, char** argv) {
    struct deque d;
    d.rearleft= d.frontleft=-1;
    d.frontright= d.rearright = max;
    insertleft(&d,10);
    insertleft(&d,11);
    insertright(&d,20);
    insertright(&d,15);
    printf("\%d \%d ", removeright(&d),removeleft(&d));
    return (EXIT_SUCCESS);
}

