#include <stdio.h>
#include <stdlib.h>

/* 合并两个已排序的子数组 */
void merge(int arr[], int leftStart, int middle, int rightEnd)
{
    int leftIndex, rightIndex, mergedIndex;
    int leftSize = middle - leftStart + 1; /* 左子数组大小 */
    int rightSize = rightEnd - middle;     /* 右子数组大小 */

    /* 创建临时数组存储左右子数组 */
    int *leftTempArray = (int *)malloc(leftSize * sizeof(int));
    int *rightTempArray = (int *)malloc(rightSize * sizeof(int));

    /* 复制数据到临时数组 */
    for (leftIndex = 0; leftIndex < leftSize; leftIndex++)
        leftTempArray[leftIndex] = arr[leftStart + leftIndex];
    for (rightIndex = 0; rightIndex < rightSize; rightIndex++)
        rightTempArray[rightIndex] = arr[middle + 1 + rightIndex];

    /* 合并临时数组回到原始数据 */
    leftIndex = 0;           /* 左子数组的当前索引 */
    rightIndex = 0;          /* 右子数组的当前索引 */
    mergedIndex = leftStart; /* 合并后数组的当前索引 */

    /* */
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftTempArray[leftIndex] <= rightTempArray[rightIndex])
        {
            arr[mergedIndex] = leftTempArray[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergedIndex] = rightTempArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    /* 复制左子数组中剩余的元素 */
    while (leftIndex < leftSize)
    {
        arr[mergedIndex] = leftTempArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    /* 复制右子数组中剩余的元素 */
    while (rightIndex < rightSize)
    {
        arr[mergedIndex] = rightTempArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    /* 释放临时数组内存 */
    free(leftTempArray);
    free(rightTempArray);
}

/* 归并排序主函数 */
void mergeSort(int arr[], int leftBound, int rightBound)
{
    if (leftBound < rightBound)
    {
        /* 找到中点， 避免溢出 */
        int midPoint = leftBound + (rightBound - leftBound) / 2;

        /* 递归排序左右子数组 */
        mergeSort(arr, leftBound, midPoint);
        mergeSort(arr, midPoint + 1, rightBound);

        /* 合并已排序的子数组 */
        merge(arr, leftBound, midPoint, rightBound);
    }
}

/* 打印数组函数 */
void printArray(int arr[], int arraysize)
{
    int elementIndex;
    for (elementIndex = 0; elementIndex < arraysize; elementIndex++)
    {
        printf("%d ", arr[elementIndex]);
    }
    printf("\n");
}

/* 测试归并排序 */
int main(void)
{
    int testArray[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);

    printf("原始数组： \n");
    printArray(testArray, arraySize);

    mergeSort(testArray, 0, arraySize - 1);

    printf("排序后数组： \n");
    printArray(testArray, arraySize);

    return 0;
}