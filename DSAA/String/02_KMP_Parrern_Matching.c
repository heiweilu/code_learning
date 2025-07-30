#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 计算模式串T的next数组
 * @param T 模式串
 * @param next next数组
 * @param j 模式串的前缀长度, 即数学函数定义中的 k
 * @param i 模式串的当前字符位置
 * @details next数组用于KMP算法中，记录模式串的前缀信息
 * next[i]表示模式串T的前i个字符的最长相等前后缀的长度
 *
 * next数组的计算过程如下：
 * 1. 初始化i=0, j=-1，next[0]=-1
 * 2. 遍历模式串T的每个字符
 * 3. 如果当前字符T[i]与前缀字符T[j]匹配，则i和j都向后移动，记录next[i+1]=j+1
 * 4. 如果不匹配，则将j回退到更短的前缀位置，继续尝试匹配
 * 5. 重复步骤2-4直到遍历完整个模式串
 *
 */
void get_next(const char *T, int *next) {
  int len = strlen(T);
  int i = 0, j = -1;
  next[0] = -1; /* i: 当前字符位置, j: 前缀长度(-1表示无前缀) */

  next[0] = -1; /* 第一个字符没有前缀，设为-1 */

  while (i < len) /* 遍历模式串的每个位置 */
  {

    if (j == -1 ||
        T[i] ==
            T[j]) /* 情况1: j==-1(无前缀) 或 情况2: 当前字符与前缀字符匹配 */
    {
      ++i; /* 移动到下一个字符 */
      ++j; /* 前缀长度增加1(j从-1变0，或从当前值+1) */
      next[i] =
          j; /* next[i+1] =
                j+1：记录当前位置模式串T的前i个字符的最长相等前后缀的长度 */
    } else   /* 情况3: 当前字符与前缀字符不匹配，回退 */
    {
      j = next[j]; /* 当前k不满足，尝试更小的k，利用已计算的结果快速回退，回退到更短的前缀位置，继续尝试匹配
                    */
    }
  }
}

/**
 * @brief KMP字符串匹配算法
 * @param S 主串（待搜索的字符串）
 * @param T 模式串（要查找的子串）
 * @return 匹配成功返回模式串在主串中的起始位置（从0开始），失败返回-1
 * @details KMP算法利用next数组避免主串指针回溯，提高匹配效率
 *
 * 匹配过程：
 * 1. 计算模式串的next数组
 * 2. 使用两个指针i(主串)和j(模式串)进行匹配
 * 3. 匹配成功时，两指针都向后移动
 * 4. 失配时，主串指针不回退，模式串指针根据next数组跳转
 * 5. 当j达到模式串长度时，匹配成功
 */

int KMP_Match(const char *S, const char *T) {
  int slen = strlen(S); /* 主串长度 */
  int tlen = strlen(T); /* 模式串长度 */

  if (tlen == 0)
    return 0; /* 空模式串匹配任意位置 */
  if (slen < tlen)
    return -1; /* 主串比模式串短，无法匹配 */

  /* 计算模式串的next数组 */
  int *next = (int *)malloc(tlen * sizeof(int));
  if (next == NULL)
    return -1; /* 内存分配失败 */

  get_next(T, next); /* 调用前面实现的get_next函数 */

  int i = 0, j = 0; /* i: 主串指针, j: 模式串指针 */

  while (i < slen && j < tlen) /* 当两个指针都未越界时继续匹配 */
  {
    if (j == -1 ||
        S[i] == T[j]) /* 情况1: j==-1(模式串回到开头) 或 情况2: 字符匹配 */
    {
      ++i; /* 主串指针向后移动 */
      ++j; /* 模式串指针向后移动 */
    } else /* 情况3: 字符不匹配 */
    {
      j = next[j]; /* 模式串指针根据next数组跳转，主串指针不回退 */
    }
  }

  free(next); /* 释放next数组内存 */

  if (j >= tlen)     /* 模式串完全匹配 */
    return i - tlen; /* 返回匹配起始位置 */
  else
    return -1; /* 匹配失败 */
}

int main() {
  char *str = "abcabcabcd";
  char *pat = "abcd";
  int pos = KMP_Match(str, pat);
  printf("pos = %d\n", pos);
  return 0;
}