int rev[MAXN + 10];
void build() {
  rev[1] = 1;
  For(i, 2, MAXN) {
    rev[i] = rev[MOD % i] * (MOD - MOD / i) % MOD;
  }
}