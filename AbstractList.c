//
//  AbstractList.c
//
//  Created by Joost Markerink on 02-03-18.
//  Copyright © 2018 Joost Markerink. All rights reserved.
//

#include "AbstractList.h"

typedef struct _ListItem ListItem;

struct _ListItem{ ListItem *next; };

typedef ListItem List;


AbstractListItem *List_getLastItem(AbstractList *lst){
    ListItem *itm=*(List **)lst;
    while(itm){
        if(!itm->next) return itm;
        itm=itm->next;
    }
    return 0;
}

void List_appendItem(AbstractList *lst,AbstractListItem *item){
    List **list=lst;
    ListItem *itm = List_getLastItem(lst);
    if(itm) itm->next=item;
    else *list=itm;
}

void List_removeItem(AbstractList *lst,const AbstractListItem *item){
    List **list=lst;

    ListItem *i=*list;
    if(*list==item){
        ListItem *itm=*list;
        *list=itm->next;
        itm->next=0;
    }else
        while(i){
            if(i->next==item){
                ListItem *itm=i->next;
                i->next=itm->next;
                itm->next=0;
                break;
            }
            i=i->next;
        }
}

char List_containsItem(const AbstractList *lst,const AbstractListItem *item){
    const ListItem *i=*(List **)lst;
    while(i){
        if(i==item) return 1;
        i=i->next;
    }
    return 0;
}

unsigned List_getNumberOfItems(const AbstractList *lst){
    unsigned count=0;
    const List *l=*(List **)lst;
    while(l){
        count++;
        l=l->next;
    }
    return count;
}

unsigned List_getItems(const AbstractList *lst,AbstractListItem **items){
    List *list=*(List **)lst;
    ListItem *i=list;
    unsigned count=0;
    while(i){
        count++;
        *items++=i;
        i=i->next;
    }
    return count;
}
