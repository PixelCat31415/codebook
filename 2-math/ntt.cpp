// avoid __int128 would be WAY FASTER!
void NTT(vector<i128> &a, int n, i128 mod, i128 rt,
  bool rev) {
  for (int i = 0, t = 0; i < n; i++) {
    if (i < t) swap(a[i], a[t]);
    for (int k = n >> 1; (t ^= k) < k; k >>= 1)
      ;
  }
  for (int len = 2; len <= n; len <<= 1) {
    int mi = len >> 1;
    i128 omega = fpow128(rt, (mod - 1) / len, mod);
    if (rev) omega = fpow128(omega, mod - 2, mod);
    Fors(i, 0, n - 1, len) {
      i128 noww = 1;
      For(j, 0, mi - 1) {
        i128 t = a[i + j];
        i128 u = a[i + j + mi] * noww % mod;
        a[i + j] = t + u;
        if (a[i + j] >= mod) a[i + j] -= mod;
        a[i + j + mi] = t - u;
        if (a[i + j + mi] < 0) a[i + j + mi] += mod;
        noww = noww * omega % mod;
      }
    }
  }
  if (rev) {
    i128 n1 = fpow128(n, mod - 2, mod);
    for (auto &i : a) i = i * n1 % mod;
  }
}
vector<i128> convolution(
  vector<i128> a, vector<i128> b, i128 mod, i128 rt) {
  int n = 1 << (__lg((LL)(sz(a) + sz(b))) + 1);
  a.resize(n);
  NTT(a, n, mod, rt, false);
  b.resize(n);
  NTT(b, n, mod, rt, false);
  vector<i128> c(n);
  For(i, 0, n - 1) c[i] = a[i] * b[i] % mod;
  NTT(c, n, mod, rt, true);
  return c;
}
// useful primes: p = r 2^k + 1
//                   p             r     k   root
//            23068673            11    21      3
//           998244353           119    23      3
// 9223372036737335297   54975513881    24      3
//           167772161             5    25      3
//          1107296257            33    25     10
//           469762049             7    26      3
//          2013265921            15    27     31