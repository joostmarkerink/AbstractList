//
//  AbstractList.c
//
/*
 MIT License
 Copyright (c) 2018 Joost Markerink
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

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
