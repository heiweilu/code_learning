#include <stdio.h>

#define MAXSIZE 5
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct {
  int array[MAXSIZE + 1]; // array[0] 可作哨兵或临时变量
  int length;
} SqList;

void swap(SqList *L, int i, int j) {
  int temp = L->array[i];
  L->array[i] = L->array[j];
  L->array[j] = temp;
}

void BubbleSort(SqList *L) {
  int i, j;
  Status flag = TRUE;

  for (i = 1; i < L->length && flag; i++) 
  {
    flag = FALSE;

    for (j = 1; j <= L->length - i; j++) 
    {
      if (L->array[j] > L->array[j + 1]) {
        swap(L, j, j + 1);
        flag = TRUE;
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

  printf("原始数组：");
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