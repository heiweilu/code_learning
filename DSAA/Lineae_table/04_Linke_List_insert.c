#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   /* 状态信息 */
typedef int ElemType; /* 元素类型 */

typedef struct Node {
  ElemType data;     /* 数据域*/
  struct Node *next; /* 指针域，指向下一个结点 */
} Node;

Status ListInsert(Node *L, int i, ElemType e) 
{
  Node *p = L; /* p指向头结点 */
  int j = 1;   /* 计数器 */

  while (j < i && p) {
    p = p->next; /* p指向下一个结点 */
    j++;         /* 计数器加1 */
  }

  if (p == NULL) {
    return ERROR; /* 如果p为空，说明第i个位置不存在 */
  }
  Node *s = (Node *)malloc(sizeof(Node)); /* 创建新结点 */
  if (s == NULL) {
    return ERROR; /* 内存分配失败 */
  }
  s->data = e;       /* 设置新结点的数据 */
  s->next = p->next; /* 新结点的next指向p的下一个结点 */
  p->next = s;       /* p的next指向新结点 */

  return OK; /* 返回成功状态 */
}

int main(void) {
  Node head = {0, NULL}; /* 头结点 */
  Node second = {2, NULL};
  Node third = {3, NULL};

  head.next = &second;  /* 头结点指向第二个结点 */
  second.next = &third; /* 第二个结点指向第三个结点 */
  ElemType e = 4;

  printf("插入前的链表元素： %d -> %d -> %d\n", head.data, second.data,
         third.data);
  if (ListInsert(&head, 2, e) == OK) {
    printf("插入成功！\n");
    printf("插入后的链表元素： %d -> %d -> %d -> %d\n", head.data, second.data,
           e, third.data);
  } else {
    printf("插入失败！\n");
  }

  return 0;
}