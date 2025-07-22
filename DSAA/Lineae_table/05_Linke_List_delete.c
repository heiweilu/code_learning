#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   /* 状态信息 */
typedef int ElemType; /* 元素类型 */

typedef struct Node {
  ElemType data;     /* 数据域 */
  struct Node *next; /* 指针域，指向下一个结点 */
} Node;

Status ListDelete(Node *L, int i, ElemType *e) {

  Node *p, *q;
  p = L; /* p指向头结点 */

  int j = 1; /* j为计数器,记录当前结点的位置 */

  while (p->next && j < i) {
    p = p->next; /* p指向第i个结点 */
    ++j;
  }

  if (p->next == NULL) {
    return ERROR; /* 如果p的下一个结点为空，说明第i个位置不存在 */
  }

  q = p->next;       /* q指向第i个结点 */
  *e = q->data;      /* 将第i个结点的数据存入e */
  p->next = q->next; /* p的next指向q的下一个结点 */

  free(q); /* 释放第i个结点的内存 */

  return OK; /* 返回成功状态 */
}

int main(void) {
  Node *head = malloc(sizeof(Node));
  Node *second = malloc(sizeof(Node));
  Node *third = malloc(sizeof(Node));
  head->data = 0;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;

  ElemType deleted;
  int pos = 2; /* 要删除的元素位置 */

  printf("删除前的链表元素： %d -> %d -> %d\n", head->data, second->data,
         third->data);

  if (ListDelete(head, pos, &deleted) == OK) {
    printf("删除位置 %d 的元素 %d 成功！\n", pos, deleted);
    printf("删除后的链表元素：");
    Node *p = head;
    while (p) {
      printf("%d", p->data);
      if (p->next)
        printf(" -> ");
      p = p->next;
    }
    printf("\n");
  } else {
    printf("删除位置 %d 的元素失败！\n", pos);
  }

  return 0;
}