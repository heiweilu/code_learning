#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
    /* 1. 计算两个字符串长度 */
    int len_haystack = strlen(haystack);
    int len_needle = strlen(needle);

    /* 2. 模式匹配 */
    for(int i = 0; i <= len_haystack - len_needle; i++)
    {
        if(strncmp(&haystack[i], needle, len_needle) == 0)
        {
            return i; // 找到匹配，返回起始位置
        }
    }

    return -1; // 未找到匹配
}

int main()
{
    char haystack[] = "hello";
    char needle[] = "ll";
    int result = strStr(haystack, needle);
    printf("Result: %d\n", result);
    return 0;
}