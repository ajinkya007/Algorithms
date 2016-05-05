/* 
 * File:   DoubleList-interface.h
 * Author: Ajinkya Wavare
 *
 * Created on February 1, 2015, 9:39 AM
 */

#ifndef DOUBLELIST_INTERFACE_H
#define	DOUBLELIST_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DOUBLELIST_INTERFACE_H */

/*Listinterface.h is created with all the function prototypes.  */
#include "DLListType.h"

/* Returns the number of elements in the list*/
int Dsize(dnode *,dnode *);
int DisEmpty(dnode *);

/*Decision questions given a pointer*/
int DisFirst(dnode *,dnode *);
int DisLast(dnode *,dnode *);

/*Function to return pointer to specific locations*/
dnode * Dfirst(dnode *);
dnode * Dlast(dnode *);
dnode * Dbefore(dnode *,dnode *);
dnode * Dafter(dnode *,dnode *);

/*Update methods*/
void DreplaceElement(dnode *,int);
void Dswap(dnode *,dnode *);
dnode * DinsertBefore(dnode *,dnode *,int);
void DinsertAfter(dnode *,dnode *,int);
dnode * DinsertFirst(dnode *,int );
void DinsertLast(dnode *,int );
dnode * Deliminate(dnode *,dnode *);

/**/
