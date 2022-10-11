void getZ(int n, const char *s, int *z) {
  z[0] = n;
  int l, r;
  l = r = 0;
  For(i, 1, n - 1) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
}