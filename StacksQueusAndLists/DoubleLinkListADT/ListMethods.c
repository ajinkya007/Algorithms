/* 
 * File:   main.c
 * Author: Ajinkya Wavare
 *
 * Created on January 31, 2015, 11:41 AM
 */

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int L_Ptr_Travs=0;
/*
 * 
 */
/*Returns the number of elements in the list.Also note the use of recursion*/
int size(node * head)
{
    static int count = 0;
    if(head == NULL) return count;
    count++;
    return size(head->next);   
}

int isEmpty(node * head)
{
    if (head == NULL) return 1;
    return 0;
}

/*Decision questions given a pointer*/
int isFirst(node * head,node * pos)
{
    if(head==pos) return 1;
    return 0;
}

int isLast(node * head,node * pos)
{
    if(pos->next == NULL) return 1;
    return 0;
}

/*Functions to return pointers to specific queries*/
node * first(node * list)
{
    return list;
    
}

node * last(node * list)
{
    if(list->next == NULL) return list;
    while(list->next!=NULL)
    {
        L_Ptr_Travs++;
        list = list->next;
    }
    return list;
    
}

node * before(node * list,node * pos)
{
    if(list == NULL || isFirst(list,pos)) return NULL;
    while(list->next != pos)
    {
        L_Ptr_Travs++;
        list=list->next;
        //skip to the node whose successor is pos
    }
    return list;
}

node * after(node * list,node * pos)
{
    if(list == NULL || isLast(list,pos))return NULL;
    // if list is empty or the position given is the last position
    while(list != pos)
    {
        list=list->next;
        // skip till we reach the position and then return the element
    }
    return list->next;
}
/*Update methods*/
void replaceElement(node * pos,int a)
{
    if(pos != NULL) pos->value = a;
    return ;
}

void swap(node * pos1,node * pos2)
{
    int temp;
    if ((pos1 == NULL)||(pos2 == NULL)) return ;
    temp = pos1->value;
    pos1->value = pos2->value;
    pos2->value = temp;
    return ;   
}

node * insertBefore(node * list,node * pos,int a)
{
    node * prev;
    node * newnode;// to store the new node
    if (pos == NULL)return;
    //Query is now meaningful ,let us allocate space for the new node.
    newnode = (node *)malloc(sizeof(node));
    newnode->value = a;
    prev = before(list,pos);
    if (prev == NULL)
    {
        //It may be the first position and hence does not have a predecessor
        if(!isFirst(list,pos)) return NULL;
        newnode->next =pos;
        return newnode;
    }
    //Insert before the first position and newnode is a pointer to a larger list
    prev->next = newnode;
    newnode->next = pos;
    return newnode;
    //Return pointer to the newly added node.
    
}

void insertAfter(node * list,node * pos,int a)
{
    node *following;
    node *newnode;
    if(pos == NULL) return ;
    newnode = (node *)malloc(sizeof(node));
    newnode->value = a;
    following = after(list,pos);
    if (following == NULL)
    {
        pos->next = newnode;
        newnode->next = NULL;
        return;
    }
    newnode->next = following;
    pos->next = newnode;
    return ;
}
node * insertFirst(node * list,int a)
{
    return insertBefore(list,list,a);
}
void insertLast(node * list,int a)
{
    if (list == NULL ) return ;
    insertAfter(list,last(list),a);
    //Careful.Check whether the first element is notnull.
}

node * eliminate(node * list,node * pos )
{
    node *prev , * succ;
    prev = before(list,pos);
    succ = after(list,pos);
    if(prev == NULL)
    {
        //position does not have a predecessor. Return the successor.
        free(pos);
        return succ;
    }
    if(succ == NULL)
    {
        //First prev check.As if the list consists of only one node it would fail if succ check is placed first.
        //position does not have a successor.return the predecessor.
        free(pos);
        prev->next = NULL;
        return prev;
    }
    //Position has both successor and a predecessor.
    free(pos);
    prev->next = succ;
    return prev;
}
// od -c ListMethods.o | more 
//od stands for octal dump.

// man od
