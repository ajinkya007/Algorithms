/* 
 * File:   DoubleListADType.h
 * Author: Ajinkya Wavare
 *
 * Created on February 1, 2015, 9:38 AM
 */
/*Extends ListMethods.c*/
#include "DLListType.h"
#include <stdio.h>
#include <stdlib.h>

//Variable global to the entire program
int DL_Ptr_Travs_Count = 0;
/*
 * 
 */
/*Returns the number of elements in the list.Also note the use of recursion*/
int Dsize(dnode * head,dnode * tail)
{
    static int count = 0;
    if(tail == NULL || head == NULL ) return -1;//meaningless call
    DL_Ptr_Travs_Count++;
    if(head->next == tail) return count + 2;
    if(head == tail) return count + 1;
    count+=2;
    return Dsize(head->next,tail->prev);   
}

int DisEmpty(dnode * head)
{
    if (head == NULL) return 1;
    return 0;
}

/*Decision questions given a pointer*/
int DisFirst(dnode * head,dnode * pos)
{
    if(head==pos) return 1;
    return 0;
}

int DisLast(dnode * head,dnode * pos)
{
    if(pos->next == NULL) return 1;
    return 0;
}

/*Functions to return pointers to specific queries*/
dnode * Dfirst(dnode * list)
{
    return list;
    // returns the list itself assuming that it points to the first location itself
}

dnode * Dlast(dnode * list)
{
    if(list->next == NULL) return list;
    while(list->next!=NULL)
    {
        list = list->next;
        DL_Ptr_Travs_Count++;
    }
    return list;
    
}

dnode * Dbefore(dnode * list,dnode * pos)
{
    if(list == NULL || DisFirst(list,pos)) return NULL;
    /*while(list->next != pos)
    {
        list=list->next;
        //skip to the dnode whose successor is pos
    }*/
    return pos->prev;
}

dnode * Dafter(dnode * list,dnode * pos)
{
    if(list == NULL || DisLast(list,pos))return NULL;
    // if list is empty or the position given is the last position
    while(list != pos)
    {
        list=list->next;
        // skip till we reach the position and then return the element
    }
    return list->next;
}
/*Update methods*/
void DreplaceElement(dnode * pos,int a)
{
    if(pos != NULL) pos->value = a;
    return ;
}

void Dswap(dnode * pos1,dnode * pos2)
{
    int temp;
    if ((pos1 == NULL)||(pos2 == NULL)) return ;
    temp = pos1->value;
    pos1->value = pos2->value;
    pos2->value = temp;
    return ;   
}

dnode * DinsertBefore(dnode * list,dnode * pos,int a)
{
    dnode * prev;
    dnode * newdnode;// to store the new dnode
    if (pos == NULL)return;
    //Query is now meaningful ,let us allocate space for the new dnode.
    newdnode = (dnode *)malloc(sizeof(dnode));
    newdnode->value = a;
    prev = Dbefore(list,pos);
    if (prev == NULL)
    {
        //It may be the first position and hence does not have a predecessor
        if(!DisFirst(list,pos)) return NULL;
        newdnode->next =pos;
        return newdnode;
    }
    //Insert before the first position and newdnode is a pointer to a larger list
    prev->next = newdnode;
    newdnode->next = pos;
    return newdnode;
    //Return pointer to the newly added dnode.
    
}

void DinsertAfter(dnode * list,dnode * pos,int a)
{
    dnode *following;
    dnode *newdnode;
    if(pos == NULL) return ;
    newdnode = (dnode *)malloc(sizeof(dnode));
    newdnode->value = a;
    following = Dafter(list,pos);
    if (following == NULL)
    {
        pos->next = newdnode;
        newdnode->next = NULL;
        return;
    }
    newdnode->next = following;
    pos->next = newdnode;
    return ;
}
dnode * DinsertFirst(dnode * list,int a)
{
    return DinsertBefore(list,list,a);
}
void DinsertLast(dnode * list,int a)
{
    if (list == NULL ) return ;
    DinsertAfter(list,Dlast(list),a);
    //Careful.Check whether the first element is notnull.
}

dnode * Deliminate(dnode * list,dnode * pos )
{
    dnode *prev , * succ;
    prev = Dbefore(list,pos);
    succ = Dafter(list,pos);
    if(prev == NULL)
    {
        //position does not have a predecessor. Return the successor.
        free(pos);
        return succ;
    }
    if(succ == NULL)
    {
        //First prev check.As if the list consists of only one dnode it would fail if succ check is placed first.
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
