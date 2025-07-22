#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Status;

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Status ClearList(Node **L) {
  Node *p, *q;
  p = (*L)->next; // 从头结点的下一个开始

  while (p) {
    q = p->next; // 保存下一个节点
    free(p);     // 释放当前节点
    p = q;       // 移动到下一个节点
  }
  (*L)->next = NULL; // 清空链表后，头结点的next指针指向NULL

  return 0; // 返回成功状态
}

int main(void) {
  Node *L = (Node *)malloc(sizeof(Node)); // 创建头结点
  L->next = NULL;                         // 初始化头结点的next指针
  int n = 5;                              // 假设我们要创建5个节点

  srand(time(0)); // 生成随机数种子

  for (int i = 0; i < n; i++) {
    Node *p = (Node *)malloc(sizeof(Node)); // 创建新节点
    p->data = rand() % 100 + 1;             // 生成0-100之间的随机数
    p->next = L->next;                      // 将新节点插入到头结点之后
    L->next = p;                            // 更新头结点的next指针
  }

  printf("Before clearing: ");

  Node *p = L->next; // 从头结点的下一个开始遍历

  while (p != NULL) {
    printf("%d -> ", p->data); // 打印节点数据
    p = p->next;               // 移动到下一个节点
  }

  printf("NULL\n");

  ClearList(&L);

  printf("After clearing: ");

  p = L->next;

  while (p != NULL) {
    printf("%d -> ", p->data);
    p = p->next;
  }

  printf("NULL\n");

  free(L);

  return 0;
}