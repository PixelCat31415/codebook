void getKMP(const int n, const char *s, int *f) {
  f[0] = -1;
  int j = -1;
  For(i, 1, n - 1) {
    while (j != -1 && s[j + 1] != s[i]) j = f[j];
    if (s[j + 1] == s[i]) j++;
    f[i] = j;
  }
}