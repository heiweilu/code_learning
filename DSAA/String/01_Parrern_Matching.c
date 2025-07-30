int Index(const char *S, const char *T) {
  int i, j;
  int s_len = strlen(S);
  int t_len = strlen(T);

  for (i = 0; i <= s_len - t_len; i++) {
    for (j = 0; j < t_len; j++) {
      if (S[i + j] != T[j]) {
        break; // 失配时跳出内层循环
      }
    }
    if (j == t_len) {
      return i; // 完全匹配，返回起始位置
    }
  }

  return -1; // 未找到
}