#include <malloc.h>
#include "LinkStack.h"
#include "LinkList.h"

typedef struct _tag_LinkStackNode
{
    LinkListNode header;
    void* item;
} TLinkStackNode;

LinkStack* LinkStack_Create()
{
    return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
    while( LinkStack_Size(stack) > 0 )
    {
        LinkStack_Pop(stack);
    }
}

int LinkStack_Push(LinkStack* stack, void* item)
{
    TLinkStackNode* node = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
    int ret = (node != NULL) && (item != NULL);
    
    if( ret )
    {
        node->item = item;
        
        ret  = LinkList_Insert(stack, (LinkListNode*)node, 0);
    }
    
    if( !ret )
    {
        free(node);
    }
    
    return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
    TLinkStackNode* node = (TLinkStackNode*)LinkList_Delete(stack, 0);
    void* ret = NULL;
    
    if( node != NULL )
    {
        ret = node->item;
        
        free(node);
    }
    
    return ret;
}

void* LinkStack_Top(LinkStack* stack)
{
    TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack, 0);
    void* ret = NULL;
    
    if( node != NULL )
    {
        ret = node->item;
    }
    
    return ret;
}

int LinkStack_Size(LinkStack* stack)
{
    return LinkList_Length(stack);
}
