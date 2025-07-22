#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

/* 头插法 */
void CreateListHead(Node **L, int n) {
  Node *p;
  int i;

  srand(time(0)); /* 生成随机数种子 */

  *L = (Node *)malloc(sizeof(Node)); /* 创建头结点 */

  (*L)->next = NULL; /* 初始化头结点的next指针 */

  for (i = 0; i < n; i++) {
    p = (Node *)malloc(sizeof(Node)); /* 创建新结点 */
    p->data = rand() % 100 + 1;       /* 生成0-100之间的随机数 */
    p->next = (*L)->next;             /* 将新结点插入到头结点之后 */
    (*L)->next = p;                   /* 更新头结点的next指针 */
  }
  (*L)->next = NULL; /* 确保头结点的next指针为NULL */
}

/* 尾插法 */
void CreateListTail(Node **L, int n) {
  Node *p, *tail; /* 尾指针 */

  int i; /* 生成随机数的循环变量 */

  srand(time(0)); /* 生成随机数种子 */

  *L = (Node *)malloc(sizeof(Node));

  (*L)->next = NULL; /* 初始化头结点的next指针 */
  tail = *L;         /* 尾指针指向头结点 */

  for (i = 0; i < n; i++) {
    p = (Node *)malloc(sizeof(Node)); /* 创建新结点 */
    p->data = rand() % 100 + 1;       /* 生成0-100之间的随机数 */
    p->next = NULL;                   /* 新结点的next指针初始化为NULL */
    tail->next = p;                   /* 将新结点插入到尾部 */
    tail = p;                         /* 更新尾指针 */
  }
  tail->next = NULL; /* 确保尾结点的next指针为NULL */
}
int main(void) {
  Node *L = NULL; /* 初始化头结点 */
  int n = 5;      /* 要创建的结点数 */

  CreateListHead(&L, n); /* 创建链表 */

  Node *p = L->next; /* 从头结点的下一个开始遍历 */

  printf("L -> ");

  while (p != NULL) {
    printf("%d -> ", p->data); /* 打印结点数据 */
    p = p->next;               /* 移动到下一个结点 */
  }
  printf("NULL\n"); /* 链表结束标志 */

  /* 释放链表内存 */
  p = L->next; /* 从头结点的下一个开始释放 */

  while (p != NULL) {
    Node *temp = p; /* 保存当前结点 */
    p = p->next;    /* 移动到下一个结点 */
    free(temp);     /* 释放当前结点内存 */
  }

  free(L); /* 释放头结点内存 */

  return 0; /* 程序结束 */
}