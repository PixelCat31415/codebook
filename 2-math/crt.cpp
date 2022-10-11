// avoid __int128 would be WAY FASTER!
struct CRT {
  int k;
  i128 mod;
  vector<i128> p;
  vector<i128> x;
  vector<vector<i128>> pr;
  void init(i128 _mod, vector<i128> &_p) {
    mod = _mod;
    p = _p;
    k = sz(p);
    x.resize(k);
    pr.resize(k);
    For(i, 0, k - 1) {
      pr[i].resize(i);
      For(j, 0, i - 1) pr[i][j] =
        fpow128(p[j], p[i] - 2, p[i]);
    }
  }
  i128 solve(const vector<i128> &r) {
    assert(sz(r) == k);
    For(i, 0, k - 1) {
      x[i] = r[i];
      For(j, 0, i - 1) {
        x[i] = pr[i][j] * (x[i] - x[j]) % p[i];
      }
      if (x[i] < 0) x[i] += p[i];
    }
    i128 ans = 0;
    Forr(i, k - 1, 0) ans = (ans * p[i] + x[i]) % mod;
    return ans;
  }
} crt;