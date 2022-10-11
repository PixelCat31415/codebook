#define LO(x) ((x) & (-x))
struct BIT {
  int n;
  int a[MAXN];
  void init(int _n) {
    n = _n;
    memset(a, 0, sizeof(a));
  }
  void add(int i, int x) {
    while (i <= n) {
      a[i] += x;
      i += LO(i);
    }
  }
  int ask(int i) {
    int ans = 0;
    while (i > 0) {
      ans += a[i];
      i -= LO(i);
    }
    return ans;
  }
} bit;