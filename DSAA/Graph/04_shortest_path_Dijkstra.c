#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 9
#define INFINITY 65535

typedef int PathMatrix[MAX_VEX]; /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAX_VEX]; /* 于存储到各点最短路径的权值和 */

typedef struct {
  char vexs[MAX_VEX];         /* 顶点表 */
  int arcs[MAX_VEX][MAX_VEX]; /* 邻接矩阵 */
  int num_vex, num_arc;       /* 图的当前顶点数和边数 */
} MGraph;

/* Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
 * @param G 图的邻接矩阵表示
 * @param v0 起始顶点
 * @param p 存储最短路径下标的数组
 * @param D 存储到各点最短路径的权值和
 */
void ShortestPath_Dijkstra(MGraph G, int v0, PathMatrix *p, ShortPathTable *D) {
  int v, w, k, min;
  int final[MAX_VEX] = {0}; /* 标记顶点是否已确定最短路径 */
  for (v = 0; v < G.num_vex; v++) {
    final[v] = 0;            /* 初始化所有顶点未确定最短路径 */
    (*D)[v] = G.arcs[v0][v]; /* 初始化到各顶点的距离 */
    (*p)[v] = v0;            /* 初始化路径为起始顶点 */
  }

  (*D)[v0] = 0;  /* 起始顶点到自身的距离为0 */
  final[v0] = 1; /* 标记起始顶点已确定最短路径 */

  /* 确定所有顶点的最短距离 */
  for (v = 1; v < G.num_vex; v++) {
    min = INFINITY; /* 初始化最小距离为正无穷大 */
    /* 找到未确定最短路径的顶点中距离起始顶点最近的顶点 */
    for (w = 0; w < G.num_vex; w++) {
      if (!final[w] && (*D)[w] < min) {
        min = (*D)[w]; /* 更新最小距离 */
        k = w;         /* 记录最短距离的顶点下标 */
      }
    }
    final[k] = 1; /* 标记该顶点已确定最短路径 */
    /* 更新其他顶点的最短路径 */
    for (w = 0; w < G.num_vex; w++) {
      if (!final[w] && (min + G.arcs[k][w] < (*D)[w])) {
        (*D)[w] = min + G.arcs[k][w]; /* 更新最短路径长度 */
        (*p)[w] = k;                  /* 更新路径下标 */
      }
    }
  }
}

// 添加main函数用于测试Dijkstra算法
int main() {
  MGraph g;
  PathMatrix p;
  ShortPathTable D;
  int i, j;

  // 初始化图的数据
  g.num_vex = 9;
  g.num_arc = 15;

  // 初始化顶点
  char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
  for (i = 0; i < g.num_vex; i++) {
    g.vexs[i] = vexs[i];
  }

  // 初始化邻接矩阵
  for (i = 0; i < g.num_vex; i++) {
    for (j = 0; j < g.num_vex; j++) {
      if (i == j) {
        g.arcs[i][j] = 0;
      } else {
        g.arcs[i][j] = INFINITY;
      }
    }
  }

  // 添加边的权值
  g.arcs[0][1] = 1; // A->B = 1
  g.arcs[0][2] = 5; // A->C = 5
  g.arcs[1][2] = 3; // B->C = 3
  g.arcs[1][3] = 7; // B->D = 7
  g.arcs[1][4] = 5; // B->E = 5
  g.arcs[2][4] = 1; // C->E = 1
  g.arcs[2][5] = 7; // C->F = 7
  g.arcs[3][6] = 3; // D->G = 3
  g.arcs[3][7] = 5; // D->H = 5
  g.arcs[4][5] = 3; // E->F = 3
  g.arcs[4][7] = 2; // E->H = 2
  g.arcs[4][8] = 5; // E->I = 5
  g.arcs[5][8] = 1; // F->I = 1
  g.arcs[6][7] = 2; // G->H = 2
  g.arcs[7][8] = 3; // H->I = 3

  // 调用Dijkstra算法计算从顶点0(A)到其他各顶点的最短路径
  ShortestPath_Dijkstra(g, 0, &p, &D);

  // 输出结果
  printf("顶点  最短路径长度  最短路径\n");
  for (i = 0; i < g.num_vex; i++) {
    printf("%c     %d          ", g.vexs[i], D[i]);
    // 打印路径
    int path[MAX_VEX];
    int path_index = 0;
    int temp = i;
    while (temp != 0) { // 回溯到起点
      path[path_index++] = temp;
      temp = p[temp];
    }
    path[path_index] = 0; // 添加起点

    // 输出路径
    for (j = path_index; j >= 0; j--) {
      printf("%c", g.vexs[path[j]]);
      if (j > 0)
        printf(" -> ");
    }
    printf("\n");
  }

  return 0;
}