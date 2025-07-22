#include <stdio.h>

#define OK 1
#define ERROR 0

typedef int Status;   /* 状态信息 */
typedef int ElemType; /* 元素类型 */

typedef struct Node {
  int data;          /* 数据域*/
  struct Node *next; /* 指针域，指向下一个结点 */
} Node;

Status GetElem(Node *L, int i, ElemType *e) 
{
  int j = 1;         /* 计数器 */
  Node *p = L->next; /* p指向头结点的下一个结点 */

  while (p && j < i) {
    p = p->next; /* p指向下一个结点 */
    j++;         /* 计数器加1 */
  }

  if (!p) /* 如果p为空，说明第i个元素不存在 */
  {
    return ERROR; /* 返回错误状态 */
  }

  *e = p->data; /* 取出数据 */

  return OK; /* 返回成功状态 */
}

int main(void) {
  Node head = {0, NULL}; // 初始化头结点
  Node second = {2, NULL};
  Node third = {3, NULL};

  head.next = &second;  // 头结点指向第二个结点
  second.next = &third; // 第二个结点指向第三个结点

  ElemType e;
  if (GetElem(&head, 2, &e) == OK) {
    printf("Element at position 2: %d\n", e);
  } else {
    printf("Error retrieving element at position 2.\n");
  }

  return 0;
}