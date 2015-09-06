
#ifndef _LGRAPH_H_
#define _LGRAPH_H_

typedef void LGraph;
typedef void LVertex;
typedef void (LGraph_Printf)(LVertex*);

LGraph* LGraph_Create(LVertex** v, int n);

void LGraph_Destroy(LGraph* graph);

void LGraph_Clear(LGraph* graph);

int LGraph_AddEdge(LGraph* graph, int v1, int v2, int w);

int LGraph_RemoveEdge(LGraph* graph, int v1, int v2);

int LGraph_GetEdge(LGraph* graph, int v1, int v2);

int LGraph_TD(LGraph* graph, int v);

int LGraph_VertexCount(LGraph* graph);

int LGraph_EdgeCount(LGraph* graph);

void LGraph_DFS(LGraph* graph, int v, LGraph_Printf* pFunc);

void LGraph_BFS(LGraph* graph, int v, LGraph_Printf* pFunc);

void LGraph_Display(LGraph* graph, LGraph_Printf* pFunc);

#endif
