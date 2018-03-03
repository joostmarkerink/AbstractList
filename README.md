# AbstractList
An abstract linked list library.

example code:
```c
typedef struct{
    void *next;
    int someOtherField;
}MyItem;

typedef struct{
   int someField;
    MyItem *list;
    int someOtherField;
}SomeStruct;

//An Abstract List Item (like MyItem) is a struct that starts with a pointer field 
//   (Its "next" field needs to be set to 0 (NULL) upon creation.)

//An Abstract List (like &SomeStruct->list) is a pointer to an item. 
//   (This field must be set to 0 (NULL) upon creation.)

int main(){
    SomeStruct *myStruct=malloc(sizeof(SomeStruct));
    myStruct->list=0;
    
    MyItem *item=malloc(sizeof(MyItem));
    item->next=0;
    
    List_appendItem(&myStruct->list,item);
    
    free(myStruct);
    free(item);
}

```
