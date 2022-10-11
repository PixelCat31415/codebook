vector<int> p;
bitset<MAXN + 10> notp;
void build() {
  For(i, 2, MAXN) {
    if (!notp[i]) p.eb(i);
    for (auto &j : p) {
      if (i * j > MAXN) break;
      notp[i * j] = 1;
      if (i % j == 0) break;
    }
  }
}