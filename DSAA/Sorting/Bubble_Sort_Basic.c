#include <stdio.h>

#define MAXSIZE 5

typedef struct {
  int array[MAXSIZE + 1]; /* 排序数组， array[0] 用作哨兵或临时变量 */
  int length;
} SqList;

void swap(SqList *L, int i, int j) {
  int temp = L->array[i];
  L->array[i] = L->array[j];
  L->array[j] = temp;
}

void BubbleSort(SqList *L) {
  int i, j;

  for (i = 1; i < L->length; i++) {
    for (j = i + 1; j <= L->length; j++) {
      if (L->array[i] > L->array[j]) {
        swap(L, i, j);
      }
    }
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

  for (i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");

  BubbleSort(&L);

  printf("排序后的数组为：");
  for (i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");

  return 0;
}
