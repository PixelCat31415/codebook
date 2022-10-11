bool is_prime(int n) {
  if (n <= 3 or ((n % 6) & 3) != 1)
    return (n | 1) == 3;
  const int owo[] = {
    2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  int r = __builtin_ctzll((int64_t)(n - 1));
  int d = n >> r;
  for (auto &p : owo)
    if (p % n) {
      int x = fpowll(p % n, d, n), i = r;
      while (x != 1 && x != n - 1 && i--)
        x = mulll(x, x, n);
      if (i != r && x != n - 1) return false;
    }
  return true;
}