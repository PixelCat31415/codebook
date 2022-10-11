// do "abc" -> "~a~b~c~" before call
void getManacher(const int n, const char *s, int *m) {
  m[0] = 1;
  int c, l;
  c = l = 0;
  For(i, 1, n - 1) {
    if (i < c + l) m[i] = min(c + l - i, m[c * 2 - i]);
    while (i + m[i] < n && i - m[i] >= 0 &&
      s[i + m[i]] == s[i - m[i]])
      m[i]++;
    if (i + m[i] > c + l) {
      c = i;
      l = m[i];
    }
  }
}