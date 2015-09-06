#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

#define AVAILABLE -1

typedef struct _tag_StaticListNode
{
    unsigned int data;
    int next;
} TStaticListNode;

typedef struct _tag_StaticList
{
    int capacity;
    TStaticListNode header;
    TStaticListNode node[];
} TStaticList;

StaticList* StaticList_Create(int capacity) // O(n)
{
    TStaticList* ret = NULL;
    int i = 0;
    
    if( capacity >= 0 )
    {
        ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->header.data = 0;
        ret->header.next = 0;
        
        for(i=1; i<=capacity; i++)
        {
            ret->node[i].next = AVAILABLE;
        }
    }
    
    return ret;
}

void StaticList_Destroy(StaticList* list) // O(1)
{
    free(list);
}

void StaticList_Clear(StaticList* list) // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    int i = 0;
    
    if( sList != NULL )
    {
        sList->header.data = 0;
        sList->header.next = 0;
        
        for(i=1; i<=sList->capacity; i++)
        {
            sList->node[i].next = AVAILABLE;
        }
    }
}

int StaticList_Length(StaticList* list) // O(1)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->header.data;
    }
    
    return ret;
}

int StaticList_Capacity(StaticList* list) // O(1)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)  // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = (sList != NULL);
    int current = 0;
    int index = 0;
    int i = 0;
    
    ret = ret && (sList->header.data + 1 <= sList->capacity);
    ret = ret && (pos >=0) && (node != NULL);
    
    if( ret )
    {
        for(i=1; i<=sList->capacity; i++)
        {
            if( sList->node[i].next == AVAILABLE )
            {
                index = i;
                break;
            }
        }
        
        sList->node[index].data = (unsigned int)node;
        
        sList->node[0] = sList->header;
        
        for(i=0; (i<pos) && (sList->node[current].next != 0); i++)
        {
            current = sList->node[current].next;
        }
        
        sList->node[index].next = sList->node[current].next;
        sList->node[current].next = index;
        
        sList->node[0].data++;
        
        sList->header = sList->node[0];
    }
    
    return ret;
}

StaticListNode* StaticList_Get(StaticList* list, int pos)  // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    StaticListNode* ret = NULL;
    int current = 0;
    int object = 0;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->header.data) )
    {
        sList->node[0] = sList->header;
        
        for(i=0; i<pos; i++)
        {
            current = sList->node[current].next;
        }
        
        object = sList->node[current].next;
        
        ret = (StaticListNode*)(sList->node[object].data);
    }
    
    return ret;
}

StaticListNode* StaticList_Delete(StaticList* list, int pos) // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    StaticListNode* ret = NULL;
    int current = 0;
    int object = 0;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->header.data) )
    {
        sList->node[0] = sList->header;
        
        for(i=0; i<pos; i++)
        {
            current = sList->node[current].next;
        }
        
        object = sList->node[current].next;
        
        sList->node[current].next = sList->node[object].next;
        
        sList->node[0].data--;
        
        sList->header = sList->node[0];
        
        sList->node[object].next = AVAILABLE;
        
        ret = (StaticListNode*)(sList->node[object].data);
    }
    
    return ret;
}


