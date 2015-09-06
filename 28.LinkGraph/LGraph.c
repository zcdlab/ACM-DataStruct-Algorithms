#include <malloc.h>
#include <stdio.h>
#include "LGraph.h"
#include "LinkList.h"
#include "LinkQueue.h"

typedef struct _tag_LGraph
{
    int count;
    LVertex** v;
    LinkList** la;
} TLGraph;

typedef struct _tag_ListNode
{
    LinkListNode header;
    int v;
    int w;
} TListNode;

static void recursive_dfs(TLGraph* graph, int v, int visited[], LGraph_Printf* pFunc)
{
    int i = 0;
    
    pFunc(graph->v[v]);
    
    visited[v] = 1;
    
    printf(", ");
    
    for(i=0; i<LinkList_Length(graph->la[v]); i++)
    {
        TListNode* node = (TListNode*)LinkList_Get(graph->la[v], i);
        
        if( !visited[node->v] )
        {
            recursive_dfs(graph, node->v, visited, pFunc);
        }
    }
}

static void bfs(TLGraph* graph, int v, int visited[], LGraph_Printf* pFunc)
{
    LinkQueue* queue = LinkQueue_Create();
    
    if( queue != NULL )
    {
        LinkQueue_Append(queue, graph->v + v);
        
        visited[v] = 1;
        
        while( LinkQueue_Length(queue) > 0 )
        {
            int i = 0;
            
            v = (LVertex**)LinkQueue_Retrieve(queue) - graph->v;
            
            pFunc(graph->v[v]);
            
            printf(", ");
            
            for(i=0; i<LinkList_Length(graph->la[v]); i++)
            {
                TListNode* node = (TListNode*)LinkList_Get(graph->la[v], i);
                
                if( !visited[node->v] )
                {
                    LinkQueue_Append(queue, graph->v + node->v);
                    
                    visited[node->v] = 1;
                }
            }
        }
    }
    
    LinkQueue_Destroy(queue);
}

LGraph* LGraph_Create(LVertex** v, int n)  // O(n)
{
    TLGraph* ret = NULL;
    int ok = 1;
    
    if( (v != NULL ) && (n > 0) )
    {
        ret = (TLGraph*)malloc(sizeof(TLGraph));
        
        if( ret != NULL )
        {
            ret->count = n;
            
            ret->v = (LVertex**)calloc(n, sizeof(LVertex*));
            
            ret->la = (LinkList**)calloc(n, sizeof(LinkList*));
            
            ok = (ret->v != NULL) && (ret->la != NULL);
            
            if( ok )
            {
                int i = 0;
                
                for(i=0; i<n; i++)
                {
                    ret->v[i] = v[i];
                }
                
                for(i=0; (i<n) && ok; i++)
                {
                    ok = ok && ((ret->la[i] = LinkList_Create()) != NULL);
                }
            }
            
            if( !ok )
            {
                if( ret->la != NULL )
                {
                    int i = 0;
                    
                    for(i=0; i<n; i++)
                    {
                        LinkList_Destroy(ret->la[i]);
                    }
                }
                
                free(ret->la);
                free(ret->v);
                free(ret);
                
                ret = NULL;
            }
        }
    }
    
    return ret;
}

void LGraph_Destroy(LGraph* graph) // O(n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    
    LGraph_Clear(tGraph);
    
    if( tGraph != NULL )
    {
        int i = 0;
        
        for(i=0; i<tGraph->count; i++)
        {
            LinkList_Destroy(tGraph->la[i]);
        }
        
        free(tGraph->la);
        free(tGraph->v);
        free(tGraph);
    }
}

void LGraph_Clear(LGraph* graph) // O(n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    
    if( tGraph != NULL )
    {
        int i = 0;
        
        for(i=0; i<tGraph->count; i++)
        {
            while( LinkList_Length(tGraph->la[i]) > 0 )
            {
                free(LinkList_Delete(tGraph->la[i], 0));
            }
        }
    }
}

int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w) // O(1)
{
    TLGraph* tGraph = (TLGraph*)graph;
    TListNode* node = NULL;
    int ret = (tGraph != NULL);
    
    ret = ret && (0 <= v1) && (v1 < tGraph->count);
    ret = ret && (0 <= v2) && (v2 < tGraph->count);
    ret = ret && (0 < w) && ((node = (TListNode*)malloc(sizeof(TListNode))) != NULL);
    
    if( ret )
    {
       node->v = v2;
       node->w = w;
       
       LinkList_Insert(tGraph->la[v1], (LinkListNode*)node, 0);
    }
    
    return ret;
}

int LGraph_RemoveEdge(LGraph* graph, int v1, int v2) // O(n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int condition = (tGraph != NULL);
    int ret = 0;
    
    condition = condition && (0 <= v1) && (v1 < tGraph->count);
    condition = condition && (0 <= v2) && (v2 < tGraph->count);
    
    if( condition )
    {
        TListNode* node = NULL;
        int i = 0;
        
        for(i=0; i<LinkList_Length(tGraph->la[v1]); i++)
        {
            node = (TListNode*)LinkList_Get(tGraph->la[v1], i);
            
            if( node->v == v2)
            {
                ret = node->w;
                
                LinkList_Delete(tGraph->la[v1], i);
                
                free(node);
                
                break;
            }
        }
    }
    
    return ret;
}

int LGraph_GetEdge(LGraph* graph, int v1, int v2) // O(n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int condition = (tGraph != NULL);
    int ret = 0;
    
    condition = condition && (0 <= v1) && (v1 < tGraph->count);
    condition = condition && (0 <= v2) && (v2 < tGraph->count);
    
    if( condition )
    {
        TListNode* node = NULL;
        int i = 0;
        
        for(i=0; i<LinkList_Length(tGraph->la[v1]); i++)
        {
            node = (TListNode*)LinkList_Get(tGraph->la[v1], i);
            
            if( node->v == v2)
            {
                ret = node->w;
                
                break;
            }
        }
    }
    
    return ret;
}

int LGraph_TD(LGraph* graph, int v) // O(n*n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int condition = (tGraph != NULL);
    int ret = 0;
    
    condition = condition && (0 <= v) && (v < tGraph->count);
    
    if( condition )
    {
        int i = 0;
        int j = 0;
        
        for(i=0; i<tGraph->count; i++)
        {
            for(j=0; j<LinkList_Length(tGraph->la[i]); j++)
            {
                TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i], j);
                
                if( node->v == v )
                {
                    ret++;
                }
            }
        }
        
        ret += LinkList_Length(tGraph->la[v]);
    }
    
    return ret;
}

int LGraph_VertexCount(LGraph* graph) // O(1)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int ret = 0;
    
    if( tGraph != NULL )
    {
        ret = tGraph->count;
    }
    
    return ret;
}

int LGraph_EdgeCount(LGraph* graph) // O(n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int ret = 0;
    
    if( tGraph != NULL )
    {
        int i = 0;
        
        for(i=0; i<tGraph->count; i++)
        {
            ret += LinkList_Length(tGraph->la[i]);
        }
    }
    
    return ret;
}

void LGraph_DFS(LGraph* graph, int v, LGraph_Printf* pFunc)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int* visited = NULL;
    int condition = (tGraph != NULL);
    
    condition = condition && (0 <= v) && (v < tGraph->count);
    condition = condition && (pFunc != NULL);
    condition = condition && ((visited = (int*)calloc(tGraph->count, sizeof(int))) != NULL);
    
    if( condition )
    {
        int i = 0;
        
        recursive_dfs(tGraph, v, visited, pFunc);
        
        for(i=0; i<tGraph->count; i++)
        {
            if( !visited[i] )
            {
                recursive_dfs(tGraph, i, visited, pFunc);
            }
        }
        
        printf("\n");
    }
    
    free(visited);
}

void LGraph_BFS(LGraph* graph, int v, LGraph_Printf* pFunc)
{
    TLGraph* tGraph = (TLGraph*)graph;
    int* visited = NULL;
    int condition = (tGraph != NULL);
    
    condition = condition && (0 <= v) && (v < tGraph->count);
    condition = condition && (pFunc != NULL);
    condition = condition && ((visited = (int*)calloc(tGraph->count, sizeof(int))) != NULL);
    
    if( condition )
    {
        int i = 0;
        
        bfs(tGraph, v, visited, pFunc);
        
        for(i=0; i<tGraph->count; i++)
        {
            if( !visited[i] )
            {
                bfs(tGraph, i, visited, pFunc);
            }
        }
        
        printf("\n");
    }
    
    free(visited);
}

void LGraph_Display(LGraph* graph, LGraph_Printf* pFunc) // O(n*n*n)
{
    TLGraph* tGraph = (TLGraph*)graph;
    
    if( (tGraph != NULL) && (pFunc != NULL) )
    {
        int i = 0;
        int j = 0;
        
        for(i=0; i<tGraph->count; i++)
        {
            printf("%d:", i);
            pFunc(tGraph->v[i]);
            printf(" ");
        }
        
        printf("\n");
        
        for(i=0; i<tGraph->count; i++)
        {
            for(j=0; j<LinkList_Length(tGraph->la[i]); j++)
            {
                TListNode* node = (TListNode*)LinkList_Get(tGraph->la[i], j);
                
                printf("<");
                pFunc(tGraph->v[i]);
                printf(", ");
                pFunc(tGraph->v[node->v]);
                printf(", %d", node->w);
                printf(">");
                printf(" ");               
            }
        }
        
        printf("\n");
    }
}

