#include <stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct {
  ElemType data;
  int cur; /* 当前节点的索引 */
} Component, StaticLinkList[MAXSIZE];

/* 释放一个静态链表结点 */
void Free_SLL(StaticLinkList space, int index) {
  space[index].cur = space[0].cur; /* 将当前节点的 cur 指向空闲链表的头 */
  space[0].cur = index;            /* 更新空闲链表头指针 */
}

int ListLength(StaticLinkList L) {
  int j = 0;
  int i = L[MAXSIZE - 1].cur; /* 最后元素的 cur 存有效数据的下标 */

  while (i) {
    i = L[i].cur; /* 获取下一个结点 */
    j++;          /* 计数结点个数 */
  }

  return j; /* 返回链表长度 */
}

/* 删除在 L 中第 i 个数据元素 e */
Status ListDelete(StaticLinkList L, int i) {
  int index, k;

  if (i < 1 || i > ListLength(L))
    return ERROR; /* i 不合法 */

  k = MAXSIZE - 1; /* 头结点的索引 */

  for (index = 1; index <= i - 1; index++)
    k = L[k].cur; /* 找到要删除元素的前一个节点 */

  index = L[k].cur; /* j 是要删除的节点的索引 */
  L[k].cur = L[index].cur; /* 前一个节点的 cur 指向要删除节点的下一个节点 */

  Free_SLL(L, index); /* 释放被删除的节点 */

  return OK; /* 删除成功 */
}

int main(void) {
  StaticLinkList L;
  int i;

  /* 初始化静态链表 */
  for (i = 0; i < MAXSIZE - 1; i++) {
    L[i].cur = i + 1; /* 设置每个节点的 cur 指向下一个节点 */
  }
  L[MAXSIZE - 1].cur = 0; /* 最后一个节点的 cur 指向空 */
  L[0].cur = 1;           /* 空闲链表的头指针指向第一个节点 */

  // 插入数据到有效链表（头插法）
  int n = 5;
  int test_data[5] = {10, 20, 30, 40, 50};
  int tail = MAXSIZE - 1; // 有效链表的尾部
  for (i = 0; i < n; i++) {
    int j = L[0].cur; // 取空闲链表头
    if (j) {
      L[0].cur = L[j].cur; // 空闲链表头后移
      L[j].data = test_data[i];
      L[j].cur = 0;    // 新节点尾部
      L[tail].cur = j; // 有效链表尾部指向新节点
      tail = j;        // 更新尾部
    }
  }

  /* 测试 ListDelete 函数 */
  printf("删除前的链表元素:\n");
  for (i = L[MAXSIZE - 1].cur; i != 0; i = L[i].cur) {
    printf("%d ", L[i].data);
  }
  if (ListDelete(L, 2) == OK) {
    printf("删除成功\n");
  } else {
    printf("删除失败\n");
  }
  printf("删除后的链表元素:\n");
  for (i = L[MAXSIZE - 1].cur; i != 0; i = L[i].cur) {
    printf("%d ", L[i].data);
  }

  return 0;
}