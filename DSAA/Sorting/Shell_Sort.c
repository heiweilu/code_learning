#include <stdio.h>

#define MAXSIZE 9
typedef struct {
  int array[MAXSIZE + 1];
  int length;
} SqList;

void ShellSort(SqList *L) {
  int i, j;
  int increment = L->length;

  do {
    increment = increment / 3 + 1;              /* 计算增量 */ 

    for (i = increment + 1; i <= L->length; i++) {
      if (L->array[i] < L->array[i - increment]) {
        L->array[0] = L->array[i];                   /* 将当前元素存入临时变量 */ 
        for (j = i - increment; j > 0 && L->array[0] < L->array[j];
             j -= increment)
          L->array[j + increment] = L->array[j];        /* 将大于当前元素的元素向后移动 */
        L->array[j + increment] = L->array[0];          /* 将当前元素放入合适位置 */
      }
    }
    printf("当前增量: %d  当前数组: ", increment);
    for (int k = 1; k <= L->length; k++)
      printf("%d ", L->array[k]);
    printf("\n");
  } while (increment > 1);
}

int main(void) {
  SqList L = {{0, 9, 1, 5, 8, 3, 7, 4, 6, 2}, 9}; /* 初始化顺序表 */ 
  ShellSort(&L);                                  /* 调用希尔排序函数 */ 

  for (int i = 1; i <= L.length; i++)
    printf("%d ", L.array[i]);
  printf("\n");

  return 0;
}