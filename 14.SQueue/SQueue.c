#include <stdio.h>
#include <malloc.h>
#include "LinkStack.h"
#include "SQueue.h"

typedef struct _tag_SQueue
{
    LinkStack* inStack;
    LinkStack* outStack;
} TSQueue;

SQueue* SQueue_Create() // O(1)
{
    TSQueue* ret = (TSQueue*)malloc(sizeof(TSQueue));
    
    if( ret != NULL )
    {
        ret->inStack = LinkStack_Create();
        ret->outStack = LinkStack_Create();
        
        if( (ret->inStack == NULL) || (ret->outStack == NULL) )
        {
            LinkStack_Destroy(ret->inStack);
            LinkStack_Destroy(ret->outStack);
            
            free(ret);
            
            ret = NULL;
        }
    }
    
    return ret;
}

void SQueue_Destroy(SQueue* queue) // O(n)
{
    SQueue_Clear(queue);
    free(queue);
}

void SQueue_Clear(SQueue* queue) // O(n)
{
    TSQueue* sQueue = (TSQueue*)queue;
    
    if( sQueue != NULL )
    {
        LinkStack_Clear(sQueue->inStack);
        LinkStack_Clear(sQueue->outStack);
    }
}

int SQueue_Append(SQueue* queue, void* item) // O(1)
{
    TSQueue* sQueue = (TSQueue*)queue;
    
    if( sQueue != NULL )
    {
        LinkStack_Push(sQueue->inStack, item);
    }
}

void* SQueue_Retrieve(SQueue* queue) // O(1)
{
    TSQueue* sQueue = (TSQueue*)queue;
    void* ret = NULL;
    
    if( sQueue != NULL )
    {
        if( LinkStack_Size(sQueue->outStack) == 0 )
        {
            while( LinkStack_Size(sQueue->inStack) > 0 )
            {
                LinkStack_Push(sQueue->outStack, LinkStack_Pop(sQueue->inStack));
            }
        }
        
        ret = LinkStack_Pop(sQueue->outStack);
    }
    
    return ret;
}

void* SQueue_Header(SQueue* queue) // O(1)
{
    TSQueue* sQueue = (TSQueue*)queue;
    void* ret = NULL;
    
    if( sQueue != NULL )
    {
        if( LinkStack_Size(sQueue->outStack) == 0 )
        {
            while( LinkStack_Size(sQueue->inStack) > 0 )
            {
                LinkStack_Push(sQueue->outStack, LinkStack_Pop(sQueue->inStack));
            }
        }
        
        ret = LinkStack_Top(sQueue->outStack);
    }
    
    return ret;
}

int SQueue_Length(SQueue* queue) // O(1)
{
    TSQueue* sQueue = (TSQueue*)queue;
    int ret = -1;
    
    if( sQueue != NULL )
    {
        ret = LinkStack_Size(sQueue->inStack) + LinkStack_Size(sQueue->outStack);
    }
    
    return ret;
}
