#include "SeqStack.h"
#include "SeqList.h"

SeqStack* SeqStack_Create(int capacity)
{
    return SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
    SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
    SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* item)
{
    return SeqList_Insert(stack, item, SeqList_Length(stack));
}

void* SeqStack_Pop(SeqStack* stack)
{
    return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

void* SeqStack_Top(SeqStack* stack)
{
    return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Size(SeqStack* stack)
{
    return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}
