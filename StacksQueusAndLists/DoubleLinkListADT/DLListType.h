/* 
 * File:   DLListType.h
 * Author: Ajinkya Wavare
 *
 * Created on February 2, 2015, 9:50 PM
 */

#ifndef DLLISTTYPE_H
#define	DLLISTTYPE_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DLLISTTYPE_H */


typedef struct Dcontainer {
    int value;
    struct Dcontainer *prev;
    struct Dcontainer *next;
}dnode;
