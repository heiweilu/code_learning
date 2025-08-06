#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int Boolean;
#define TRUE 1
#define FALSE 0

Boolean visited[MAX];

/* 队列结构定义 */
typedef struct Queue {
  int data[MAX];
  int front; /* 队头 */
  int rear;  /* 队尾 */
} Queue;

/* 入队操作 */
void EnQueue(Queue *Q, int item) {
  if ((Q->rear + 1) % MAX == Q->front)
    return; /* 队列满 */

  Q->data[Q->rear] = item;       /* 入队 */
  Q->rear = (Q->rear + 1) % MAX; /* 更新队尾指针 */
}

/* 出队操作 */
int DeQueue(Queue *Q) {
  if (Q->front == Q->rear)
    return -1; /* 队列空 */

  int item = Q->data[Q->front];    /* 取队头元素 */
  Q->front = (Q->front + 1) % MAX; /* 队头指针后移 */

  return item;
}

/* 队列判空操作 */
int IsEmpty(Queue *Q) { return Q->front == Q->rear; }

typedef struct {
  char vexs[MAX];     /* 顶点表 */
  int arcs[MAX][MAX]; /* 邻接矩阵 */
  int vexnum, arcnum; /* 图的当前顶点数和边数 */
} MGraph;

/* 广度优先搜索算法 */
void BFS(MGraph *G, int start) {
  Queue Q;
  Q.front = Q.rear = 0;          /* 初始化队列 */
  visited[start] = TRUE;         /* 标记起始顶点为已访问 */
  printf("%c ", G->vexs[start]); /* 输出起始顶点 */
  EnQueue(&Q, start);            /* 入队起始顶点 */

  while (!IsEmpty(&Q)) {
    int v = DeQueue(&Q); /* 出队一个顶点 */
    for (int j = 0; j < G->vexnum; j++) {
      if (G->arcs[v][j] == 1 && !visited[j]) { /* 如果有边且未访问 */
        visited[j] = TRUE;                     /* 标记为已访问 */
        printf("%c ", G->vexs[j]);             /* 输出该顶点 */
        EnQueue(&Q, j);                        /* 入队该顶点 */
      }
    }
  }
}
void BFS_Traverse(MGraph *G) {
  for (int i = 0; i < G->vexnum; i++) {
    visited[i] = FALSE; /* 初始化所有顶点为未访问 */
  }
  for (int i = 0; i < G->vexnum; i++) {
    if (!visited[i]) { /* 如果顶点i未被访问 */
      BFS(G, i);       /* 从顶点i开始广度优先遍历 */
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

  /* 邻接矩阵初始化 */
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

  printf("广度优先遍历结果：\n");
  BFS_Traverse(&G); /* 执行广度优先遍历 */

  return 0;
}