int fpow(int b, int p, const int &mod = MOD) {
  int ans = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) ans = ans * b % mod;
  return ans;
}