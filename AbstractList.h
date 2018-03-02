//
//  AbstractList.h
//
//  Created by Joost Markerink on 02-03-18.
//  Copyright © 2018 Joost Markerink. All rights reserved.
//

#ifndef AbstractList_h
#define AbstractList_h

typedef void AbstractListItem;
typedef void AbstractList;


AbstractListItem *  List_getLastItem        (      AbstractList *);
void                List_appendItem         (      AbstractList *,      AbstractListItem *);
char                List_containsItem       (const AbstractList *,const AbstractListItem *);
void                List_removeItem         (      AbstractList *,const AbstractListItem *);
unsigned            List_getNumberOfItems   (const AbstractList *);
unsigned            List_getItems           (const AbstractList *,      AbstractListItem **);

#endif /* AbstractList_h */
