#include <stdio.h>

#define MAXSIZE 5
#define OK 1
#define ERROR 0

typedef struct {
  int array[MAXSIZE + 1]; /* 排序数组， array[0] 用作哨兵或临时变量 */
  int length;
} SqList;

void swap(SqList *L, int i, int j) {
  int temp = L->array[i];
  L->array[i] = L->array[j];
  L->array[j] = temp;
}
void SelectSort(SqList *L) {
  int i, j, minIndex;
  for (i = 1; i < L->length; i++) {
    minIndex = i;
    for (j = i + 1; j <= L->length; j++) {
      if (L->array[j] < L->array[minIndex])
        minIndex = j;
    }
    if (minIndex != i)
      swap(L, i, minIndex);
  }
}

int main(void) {
  SqList L;
  L.length = 5;
  L.array[1] = 5;
  L.array[2] = 4;
  L.array[3] = 3;
  L.array[4] = 2;
  L.array[5] = 1;

  printf("排序前：\n");
  for (int i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");

  SelectSort(&L);

  printf("排序后：\n");
  for (int i = 1; i <= L.length; i++) {
    printf("%d ", L.array[i]);
  }
  printf("\n");
  return 0;
}