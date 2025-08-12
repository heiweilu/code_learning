#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char *word1, char *word2) {
  int len1 = strlen(word1);
  int len2 = strlen(word2);
  int maxlen = len1 > len2 ? len1 : len2;

  char *mergechar = (char *)malloc((len1 + len2 + 1) * sizeof(char));
  if (!mergechar)
    return NULL;

  int origin_index, merge_index = 0;

  for (origin_index = 0; origin_index < maxlen; origin_index++) {
    if (origin_index < len1)
      mergechar[merge_index++] = word1[origin_index];
    if (origin_index < len2)
      mergechar[merge_index++] = word2[origin_index];
  }
  mergechar[merge_index] = '\0';
  return mergechar;
}

int main(void) {
  char *word1 = "abc";
  char *word2 = "12345";

  char *mergechar = mergeAlternately(word1, word2);
  printf("Merged string: %s\n", mergechar);
  free(mergechar);
  return 0;
}