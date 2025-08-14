#include <stdio.h>

#define MAXSIZE 20

typedef struct {
  int array[MAXSIZE];
  int length;
} SqList;

void swap(SqList *L, int i, int j) {
  int temp = L->array[i];
  L->array[i] = L->array[j];
  L->array[j] = temp;
}

/**
 * 调整堆结构，使其满足大顶堆性质
 * @param L 待调整的顺序表
 * @param startIndex 起始调整位置索引
 * @param endIndex 结束位置索引
 */
void HeapAdjust(SqList *L, int startIndex, int endIndex) {
  int holdValue, childIndex;
  holdValue = L->array[startIndex]; /* 记录当前节点值 */

  for (childIndex = 2 * startIndex; childIndex <= endIndex; childIndex *= 2) {
    if (childIndex < endIndex &&
        L->array[childIndex] < L->array[childIndex + 1])
      childIndex++;
    if (holdValue > L->array[childIndex])
      break;

    L->array[startIndex] = L->array[childIndex];
    startIndex = childIndex;
  }
  L->array[startIndex] = holdValue;
}

void HeapSort(SqList *L) {
  int i;
  for (i = L->length / 2; i > 0; i--)
    HeapAdjust(L, i, L->length); /* 构建大顶堆 */

  for (i = L->length; i > 1; i--) {
    swap(L, 1, i); /* 将堆顶元素与当前最后一个元素交换 */
    HeapAdjust(L, 1, i - 1); /* 调整堆结构 */
  }
}

int main(void) {
  SqList L = {{0, 50, 10, 90, 30, 70, 40, 80, 60, 20}, 10};
  printf("排序前：");
  int i;

  for (i = 1; i <= L.length; i++)
    printf("%d ", L.array[i]);
  printf("\n");

  HeapSort(&L);
  printf("排序后：");
  for (i = 1; i <= L.length; i++)
    printf("%d ", L.array[i]);

  return 0;
}