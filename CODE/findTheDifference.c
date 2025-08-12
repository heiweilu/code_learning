#include <stdio.h>
#include <string.h>

char findTheDifference(char *s, char *t) {
  int sum_s = 0, sum_t = 0;

  /* 计算字符串s的ASCII和 */
  for (int i = 0; i < strlen(s); i++) {
    sum_s += s[i];
  }

  /* 计算字符串t的ASCII和 */
  for (int i = 0; i < strlen(t); i++) {
    sum_t += t[i];
  }

  /* 差值就是多出来的字符 */
  return (char)(sum_t - sum_s);
}

char findTheDifference1(char *s, char *t) {
  char result = 0;

  /* 对字符串s中的所有字符进行异或 */
  for (int i = 0; i < strlen(s); i++) {
    result ^= s[i];
  }

  /* 对字符串t中的所有字符进行异或 */
  for (int i = 0; i < strlen(t); i++) {
    result ^= t[i];
  }

  /* 相同的字符会被异或抵消，剩下的就是多出来的字符 */
  return result;
}
int main(void) {
  char *s = "abcd";
  char *t = "abcde";
  char result1 = findTheDifference(s, t);
  char result2 = findTheDifference1(s, t);
  printf("result1 is: %c\n", result1);
  printf("result2 is: %c\n", result2);

  return 0;
}