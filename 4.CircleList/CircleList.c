#include <stdio.h>
#include <malloc.h>
#include "CircleList.h"

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode* slider;
    int length;
} TCircleList;

CircleList* CircleList_Create() // O(1)
{
    TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
    
    if( ret != NULL )
    {
        ret->length = 0;
        ret->header.next = NULL;
        ret->slider = NULL;
    }
    
    return ret;
}

void CircleList_Destroy(CircleList* list) // O(1)
{
    free(list);
}

void CircleList_Clear(CircleList* list) // O(1)
{
    TCircleList* sList = (TCircleList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;
        sList->header.next = NULL;
        sList->slider = NULL;
    }
}

int CircleList_Length(CircleList* list) // O(1)
{
    TCircleList* sList = (TCircleList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) // O(n)
{ 
    TCircleList* sList = (TCircleList*)list;
    int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
    int i = 0;
    
    if( ret )
    {
        CircleListNode* current = (CircleListNode*)sList;
        
        for(i=0; (i<pos) && (current->next != NULL); i++)
        {
            current = current->next;
        }
        
        node->next = current->next;
        current->next = node;
        
        if( sList->length == 0 )
        {
            sList->slider = node;
            node->next = node;
        }
        
        sList->length++;
    }
    
    return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) // O(n)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    int i = 0;
    
    if( (sList != NULL) && (pos >= 0) )
    {
        CircleListNode* current = (CircleListNode*)sList;
        
        for(i=0; i<pos; i++)
        {
            current = current->next;
        }
        
        ret = current->next;
    }
    
    return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) // O(n)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    int i = 0;
    
    if( (sList != NULL) && (pos >= 0) )
    {
        CircleListNode* current = (CircleListNode*)sList;
        CircleListNode* first = sList->header.next;
        CircleListNode* last = (CircleListNode*)CircleList_Get(sList, sList->length - 1);
        
        for(i=0; i<pos; i++)
        {
            current = current->next;
        }
        
        ret = current->next;
        current->next = ret->next;
        
        sList->length--;
        
        if( first == ret )
        {
            sList->header.next = ret->next;
            last->next = ret->next;
        }
        
        if( sList->slider == ret )
        {
            sList->slider = ret->next;
        }
        
        if( sList->length == 0 )
        {
            sList->header.next = NULL;
            sList->slider = NULL;
        }
    }
    
    return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) // O(n)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    int i = 0;
    
    if( sList != NULL )
    {
        CircleListNode* current = (CircleListNode*)sList;
        
        for(i=0; i<sList->length; i++)
        {
            if( current->next == node )
            {
                ret = current->next;
                break;
            }
            
            current = current->next;
        }
        
        if( ret != NULL )
        {
            CircleList_Delete(sList, i);
        }
    }
    
    return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) // O(1)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    
    if( sList != NULL )
    {
        sList->slider = sList->header.next;
        ret = sList->slider;
    }
    
    return ret;
}

CircleListNode* CircleList_Current(CircleList* list) // O(1)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    
    if( sList != NULL )
    {
        ret = sList->slider;
    }
    
    return ret;
}

CircleListNode* CircleList_Next(CircleList* list) // O(1)
{
    TCircleList* sList = (TCircleList*)list;
    CircleListNode* ret = NULL;
    
    if( (sList != NULL) && (sList->slider != NULL) )
    {
        ret = sList->slider;
        sList->slider = ret->next;
    }
    
    return ret;
}

