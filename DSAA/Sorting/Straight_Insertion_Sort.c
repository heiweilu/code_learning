#include <stdio.h>

#define MAXSIZE 5

typedef struct {
  int array[MAXSIZE + 1]; /* array[0] 作为哨兵 */
  int length;
} SqList;

void StraightInsertionSort(SqList *L) {
  int i, j;
  for (i = 2; i <= L->length; i++) {
    L->array[0] = L->array[i]; /* 设置哨兵 */
    j = i - 1;
    while (L->array[0] < L->array[j]) { /* 与前面元素比较 */
      L->array[j + 1] = L->array[j];    /* 后移 */
      j--;
    }
    L->array[j + 1] = L->array[0]; /* 插入哨兵到正确位置 */
  }
}

int main(void) {
  SqList L;
  int i;
  L.length = 5;
  L.array[1] = 9;
  L.array[2] = 1;
  L.array[3] = 5;
  L.array[4] = 8;
  L.array[5] = 3;

  printf("原始数组：");
  for (i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");

  StraightInsertionSort(&L);

  printf("排序后的数组：");
  for (i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");

  return 0;
}