#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int Boolean;
#define TRUE 1
#define FALSE 0

Boolean visited[MAX];

typedef struct {
  char vexs[MAX];     /* 顶点表 */
  int arcs[MAX][MAX]; /* 邻接矩阵 */
  int vexnum, arcnum; /* 图的当前顶点数和边数 */
} MGraph;

void DFS(MGraph *G, int i) {
  int j;
  visited[i] = TRUE; /* 标记顶点vi为已访问 */
  printf("%c", G->vexs[i]);
  for (j = 0; j < G->vexnum; j++) {
    if (G->arcs[i][j] == 1 && !visited[j]) /* 如果顶点vi与vj有边且vj未被访问 */
    {
      DFS(G, j); /* 递归访问顶点j */
    }
  }
}

void DFS_Traverse(MGraph *G) {
  int i;
  for (i = 0; i < G->vexnum; i++) {
    visited[i] = FALSE; /* 初始化所有顶点为未访问 */
  }
  for (i = 0; i < G->vexnum; i++) {
    if (!visited[i]) /* 如果顶点i未被访问 */
    {
      DFS(G, i); /* 从顶点i开始深度优先遍历 */
    }
  }
}

int main() {
  MGraph G;

  /* 创建图G */
  G.vexnum = 5; /* 假设有5个顶点 */
  G.arcnum = 6; /* 假设有6条边 */

  /* 顶点表 */
  G.vexs[0] = 'A';
  G.vexs[1] = 'B';
  G.vexs[2] = 'C';
  G.vexs[3] = 'D';
  G.vexs[4] = 'E';

  /* 邻接矩阵 */
  for (int i = 0; i < G.vexnum; i++) {
    for (int j = 0; j < G.vexnum; j++) {
      G.arcs[i][j] = 0; /* 初始化邻接矩阵 */
    }
  }

  /* 添加边(无向图) */
  G.arcs[0][1] = 1;
  G.arcs[1][0] = 1; // A-B
  G.arcs[0][2] = 1;
  G.arcs[2][0] = 1; // A-C
  G.arcs[1][3] = 1;
  G.arcs[3][1] = 1; // B-D
  G.arcs[2][4] = 1;
  G.arcs[4][2] = 1; // C-E
  G.arcs[3][4] = 1;
  G.arcs[4][3] = 1; // D-E

  DFS_Traverse(&G);
  printf(" \n");
  return 0;
}