using cpx = complex<double>;
const double PI = acos(-1);
void FFT(vector<cpx> &v, int n, bool rev) {
  assert(__builtin_popcountll(n) == 1);
  for (int i = 0, j = 0; i < n; i++) {
    if (i < j) swap(v[i], v[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  for (int m = 1; m < n; m <<= 1) {
    cpx omega =
      exp(cpx(0, (rev ? -1 : 1) * 2 * PI / (m * 2)));
    for (int s = 0; s < n; s += m * 2) {
      cpx now = 1;
      for (int i = 0; i < m; i++) {
        cpx u = v[s + i];
        cpx t = v[s + i + m] * now;
        v[s + i] = u + t;
        v[s + i + m] = u - t;
        now *= omega;
      }
    }
  }
  if (rev)
    for (auto &i : v) i /= n;
}
vector<cpx> convolution(vector<cpx> a, vector<cpx> b) {
  int n = 1 << (__lg(sz(a) + sz(b)) + 1);
  a.resize(n);
  b.resize(n);
  FFT(a, n, 0);
  FFT(b, n, 0);
  vector<cpx> c(n);
  For(i, 0, n - 1) c[i] = a[i] * b[i];
  FFT(c, n, 1);
  return c;
}