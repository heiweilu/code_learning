#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

typedef struct EdgeNode /* 边表结点 */
{
  int adjvex;      /* 邻接点域，存储该顶点对应的下标 */
  EdgeType weight; /* 用于存储权值，对于非网图可以不需要 */
  struct EdgeNode *next; /* 链域，指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
  VertexType data;             /* 顶点域，存储顶点信息 */
  EdgeNode *firstedge;         /* 边表头指针 */
} VertexNode, AdjList[MAXVEX]; /* 图的邻接表类型定义 */

typedef struct /* 图的邻接表结构 */
{
  AdjList adjList;
  int numVertexes, numEdges; /* 图的当前顶点数和边数 */
} GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
  int i, j, k, w;
  EdgeNode *e;

  printf("请输入顶点数和边数：\n");
  scanf("%d %d", &G->numVertexes, &G->numEdges);

  for (i = 0; i < G->numVertexes; i++) {
    scanf(" %c", &G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }

  for (k = 0; k < G->numEdges; k++) {
    printf("请输入边(vi,vj)上的顶点序号：\n");
    scanf("%d, %d", &i, &j);

    /* 建立从顶点i到顶点j的连接 */
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;                     /* 邻接点序号 */
    e->next = G->adjList[i].firstedge; /* 插入链表头部 */
    G->adjList[i].firstedge = e;       /* 头插法 */

    /* 建立从顶点j到顶点i的连接 */
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = i;                     /* 邻接点序号 */
    e->next = G->adjList[j].firstedge; /* 插入链表头部 */
    G->adjList[j].firstedge = e;       /* 头插法 */
  }
}