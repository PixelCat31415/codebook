int sa[MAXN + 10];
int rk[MAXN + 10];
int lcp[MAXN + 10];
// build SA in O(N log^2 N)
void getSA(int n, const char *s) {
  vector<int> r(n + 1), r2(n + 1);
  r[n] = r2[n] = -1;
  For(i, 0, n - 1) {
    sa[i] = i;
    r[i] = s[i];
  }
  for (int len = 1; len <= n; len <<= 1) {
    auto cmp = [&](int i, int j) {
      if (r[i] != r[j]) return r[i] < r[j];
      i += len;
      j += len;
      if (i < n && j < n) return r[i] < r[j];
      return i > j;
    };
    sort(sa, sa + n, cmp);
    r2[sa[0]] = 0;
    For(i, 1, n - 1) r2[sa[i]] =
      r2[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    swap(r, r2);
    if (r[n - 1] == n - 1) return;
  }
}
// call after getSA()
void getLCP(int n, const char *s) {
  For(i, 0, n - 1) rk[sa[i]] = i;
  for (int now = 0, i = 0; i < n; i++) {
    if (rk[i] == 0) lcp[rk[i]] = 0;
    else {
      if (now) now--;
      int j = sa[rk[i] - 1];
      while (i + now < n && j + now < n &&
        s[i + now] == s[j + now])
        now++;
      lcp[rk[i]] = now;
    }
  }
}