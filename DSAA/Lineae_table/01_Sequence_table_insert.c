#include <stdio.h>

#define OK 1        /* 执行成功 */
#define ERROR 0     /* 执行失败 */
#define MAXSIZE 100 /* 顺序表最大长度 */

typedef int Status;   /* 返回执行状态 */
typedef int ElemType; /* 元素类型，这里假设为int */

typedef struct {
  ElemType data[MAXSIZE]; /* 存储元素的数组 */
  int length;             /* 当前顺序表长度 */
} SqList;

Status ListInsert(SqList *L, int i, ElemType e) 
{
  if (L->length == MAXSIZE) /* 顺序表已满 */
    return ERROR;

  if (i < 1 || i > L->length + 1) /* 插入位置不合法 */
    return ERROR;

  if (i <= L->length) /* 如果插入位置不在表尾。因为表尾不需要移动元素 */
  {
    for (int k = L->length - 1; k >= i - 1; k--) /* 移动元素 */
      L->data[k + 1] = L->data[k];
  }
  L->data[i - 1] = e; /* 插入新元素 */
  L->length++;        /* 更新顺序表长度 */

  return OK; /* 返回成功状态 */
}

int main(void) 
{
  SqList L = {{1, 2, 3, 4, 5}, 5}; /* 初始化顺序表 */
  ElemType newElement = 10;        /* 要插入的新元素 */
  int pos = 3;                     /* 要插入的位置 */

  printf("插入前顺序表的元素为：");
  for (int i = 0; i < L.length; i++) {
    printf("%d ", L.data[i]);
  }
  printf("\n");

  if (ListInsert(&L, pos, newElement) == OK) {
    printf("在位置 %d 插入元素 %d 成功！\n", pos, newElement);
    printf("插入后顺序表的元素为：");
    for (int i = 0; i < L.length; i++) {
      printf("%d ", L.data[i]);
    }
    printf("\n");
  } else {
    printf("在位置 %d 插入元素失败！\n", pos);
  }

  return 0;
}