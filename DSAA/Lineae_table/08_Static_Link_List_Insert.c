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

/* 申请静态链表节点 */
static int Malloc_SLL(StaticLinkList space) {
  int i = space[0].cur; /* 获取第一个空闲节点的索引 */

  if (i)
    space[0].cur = space[i].cur; /* 更新头结点的空闲指针,指向下一个位置 */

  return i; /* 返回分配的节点索引 */
}

/* 统计有效链表长度 */
static int ListLength(StaticLinkList L) {
  int len = 0;
  int i = L[MAXSIZE - 1].cur; /* 最后元素的 cur 存有效数据的下标 */
  while (i != 0) {
    len++;
    i = L[i].cur; /* 移动到下一个节点,下一位置数据为空，则cur用0表示 */
  }
  return len;
}

/* 插入元素 */
static Status ListInsert(StaticLinkList L, int i, ElemType e) {
  int j, k, l;

  k = MAXSIZE - 1; /* 头结点的索引 */
  int len = ListLength(L);
  if (i < 1 || i > len + 1)
    return ERROR;

  j = Malloc_SLL(L); /* 分配新节点 */

  if (j) {
    L[j].data = e;
    for (l = 1; l < i; l++)
      k = L[k].cur;      /* 找到插入位置的前一个节点 */
    L[j].cur = L[k].cur; /* 新节点的cur指向插入位置的下一个节点 */
    L[k].cur = j;        /* 前一个节点的cur指向新节点 */
    return OK;           /* 插入成功 */
  }

  return ERROR; /* 插入失败，空间不足 */
}

int main(void) {
  StaticLinkList L;
  int i, n;

  /* 初始化静态链表 */
  for (i = 0; i < MAXSIZE - 1; i++)
    L[i].cur = i + 1; /* 设置每个节点的cur指向下一个节点 */

  L[MAXSIZE - 1].cur = 0; /* 尾节点的cur指向0 */
  L[0].cur = 1;           /* 头结点的cur指向第一个空闲节点 */

  n = 5;
  int test_data[5] = {10, 20, 30, 40, 50};

  for (i = 1; i <= n; i++) {
    if (ListInsert(L, i, test_data[i - 1]) == OK)
      printf("Element %d inserted successfully.\n", test_data[i - 1]);
    else
      printf("Failed to insert element %d.\n", test_data[i - 1]);
  }

  /* 打印插入前链表内容 */
  printf("Static Linked List before insert: ");

  int print_cnt = 0;

  for (i = L[MAXSIZE - 1].cur; i != 0 && print_cnt < MAXSIZE;
       i = L[i].cur, print_cnt++)
    printf("%d ", L[i].data);

  if (print_cnt >= MAXSIZE)
    printf("[Error] Possible loop detected!\n");
  else
    printf("\n");

  /* 在第3个位置插入99 */
  if (ListInsert(L, 3, 99) == OK)
    printf("Element 99 inserted at position 3 successfully.\n");
  else
    printf("Failed to insert element 99 at position 3.\n");

  /* 打印插入后链表内容 */
  printf("Static Linked List after insert: ");

  print_cnt = 0;

  for (i = L[MAXSIZE - 1].cur; i != 0 && print_cnt < MAXSIZE;
       i = L[i].cur, print_cnt++)
    printf("%d ", L[i].data);

  if (print_cnt >= MAXSIZE)
    printf("[Error] Possible loop detected!\n");
  else
    printf("\n");

  return 0;
}