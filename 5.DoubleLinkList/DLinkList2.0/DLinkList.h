#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_

typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
struct _tag_DLinkListNode
{
    DLinkListNode* next;
    DLinkListNode* pre;
};

DLinkList* DLinkList_Create();

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

DLinkListNode* DLinkList_Reset(DLinkList* list);

DLinkListNode* DLinkList_Current(DLinkList* list);

DLinkListNode* DLinkList_Next(DLinkList* list);

DLinkListNode* DLinkList_Pre(DLinkList* list);

#endif
