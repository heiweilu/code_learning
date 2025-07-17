#include <stdio.h>

typedef int Status; /* 状态信息 */
typedef int ElemType; /* 元素类型 */
#define OK 1 /* 执行成功 */
#define ERROR 0 /* 执行失败 */
#define MAXSIZE 100 /* 顺序表最大长度 */

typedef struct{
    ElemType data[MAXSIZE]; /* 存储元素的数组 */
    int length; /* 当前顺序表长度 */
}SqList; /* 顺序表类型 */

Status ListDelete(SqList *L, int i, ElemType *e)
{
    /* 1.错误判断 */
    if(L->length == 0) /* 顺序表为空 */
        return ERROR;
    if(i < 1 || i > L->length) /* 删除位置不合法 */
        return ERROR;

    /* 2. 取出要删除的元素，存放到指针e中 */
    *e = L->data[i - 1]; 

    /* 3. 移动线性表的元素：从删除位置开始，依次把后面的元素往前移1位 */
    if(i < L->length) /* 如果删除位置不是表尾 */
    {
        for(int k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k]; /* 移动元素 */
    }

    /* 4. 线性表长度减一 */
    L->length--; /* 更新顺序表长度 */

    /* 5. 返回成功状态 */
    return OK; /* 返回成功状态 */
}
int main() {

    SqList L = {{1, 2, 3, 4, 5}, 5}; /* 初始化顺序表 */
    int deleted;
    int pos = 3; /* 要删除的元素位置 */

    printf("删除前顺序表的元素为：");
    for(int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    if(ListDelete(&L, pos, &deleted) == OK){
        printf("删除位置 %d 的元素 %d 成功！\n", pos, deleted);
        printf("删除后顺序表的元素为：");
        for(int i = 0; i < L.length; i++) {
            printf("%d ", L.data[i]);
        }
        printf("\n");
    }else {
        printf("删除位置 %d 的元素失败！\n", pos);
    }

    return 0;
}