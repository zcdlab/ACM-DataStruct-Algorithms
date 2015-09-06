#include <stdio.h>
#include <malloc.h>
#include "SeqQueue.h"

typedef unsigned int TSeqQueueNode;

typedef struct _tag_SeqQueue
{
    int capacity;
    int length;
    int front;
    int rear;
    TSeqQueueNode* node;
} TSeqQueue;

SeqQueue* SeqQueue_Create(int capacity) // O(1)
{
    TSeqQueue* ret = NULL;
    
    if( capacity >= 0 )
    {
        ret = (TSeqQueue*)malloc(sizeof(TSeqQueue) + sizeof(TSeqQueueNode) * capacity);
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->front = 0;
        ret->rear = 0;
        ret->node = (TSeqQueueNode*)(ret + 1);
    }
    
    return ret;
}

void SeqQueue_Destroy(SeqQueue* queue) // O(1)
{
    free(queue);
}

void SeqQueue_Clear(SeqQueue* queue) // O(1)
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    
    if( sQueue != NULL )
    {
        sQueue->length = 0;
        sQueue->front = 0;
        sQueue->rear = 0;
    }
}

int SeqQueue_Append(SeqQueue* queue, void* item) // O(1)
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    int ret = (sQueue != NULL) && (item != NULL);
    
    ret = ret && (sQueue->length + 1 <= sQueue->capacity);
    
    if( ret )
    {
        sQueue->node[sQueue->rear] = (TSeqQueueNode)item;
        
        sQueue->rear = (sQueue->rear + 1) % sQueue->capacity;
        
        sQueue->length++;
    }
    
    return ret;
}

void* SeqQueue_Retrieve(SeqQueue* queue) // O(1)
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    void* ret = SeqQueue_Header(queue);
    
    if( ret != NULL )
    {
        sQueue->front = (sQueue->front + 1) % sQueue->capacity;
        
        sQueue->length--;
    }
    
    return ret;
}

void* SeqQueue_Header(SeqQueue* queue) // O(1) 
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    void* ret = NULL;
    
    if( (sQueue != NULL) && (sQueue->length > 0) )
    {
        ret = (void*)(sQueue->node[sQueue->front]);
    }
    
    return ret;
}

int SeqQueue_Length(SeqQueue* queue) // O(1)
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    int ret = -1;
    
    if( sQueue != NULL )
    {
        ret = sQueue->length;
    }
    
    return ret;
}

int SeqQueue_Capacity(SeqQueue* queue) // O(1)
{
    TSeqQueue* sQueue = (TSeqQueue*)queue;
    int ret = -1;
    
    if( sQueue != NULL )
    {
        ret = sQueue->capacity;
    }
    
    return ret;
}
