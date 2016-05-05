/* 
 * File:   List-Interface.h
 * Author: Ajinkya Wavare
 *
 * Created on February 2, 2015, 10:55 PM
 */

#ifndef LIST_INTERFACE_H
#define	LIST_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LIST_INTERFACE_H */

/*Listinterface.h is created with all the function prototypes.  */
#include "List.h"

/* Returns the number of elements in the list*/
int size(node *);
int isEmpty(node *);

/*Decision questions given a pointer*/
int isFirst(node *,node *);
int isLast(node *,node *);

/*Function to return pointer to specific locations*/
node * first(node *);
node * last(node *);
node * before(node *,node *);
node * after(node *,node *);

/*Update methods*/
void replaceElement(node *,int);
void swap(node *,node *);
node * insertBefore(node *,node *,int);
void insertAfter(node *,node *,int);
node * insertFirst(node *,int );
void insertLast(node *,int );
node * eliminate(node *,node *);

/**/