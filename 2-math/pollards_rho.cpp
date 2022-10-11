int rho(int n) {
  static int c = 48763;
  auto next = [&n](int x) {
    return (mulll(x, x, n) + c);
  };
  int a = 2, b = 2, g, gg = 1;
  for (int r = 1; (r & 127) || __gcd(gg, n) == 1;
       r++) {
    if (a == b) {
      c = rng() % (n - 1) + 1;
      a = 2;
      b = next(2);
    }
    g = mulll(gg, (a > b ? a - b : b - a), n);
    gg = g ? g : gg;
    a = next(a);
    b = next(next(b));
  }
  return __gcd(gg, n);
}