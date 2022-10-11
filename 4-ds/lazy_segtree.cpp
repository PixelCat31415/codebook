#define L(id) ((id)*2 + 1)
#define R(id) ((id)*2 + 2)
struct SegTree {
  struct SegNode {
    // info & tags
    void tag(...) {
      // put new tags & update info
    }
  } a[MAXN << 2];
  void pull(int id) {
    // merge info
  }
  void push(int id) {
    // push tags
  }
  void build(int id, int l, int r, ...) {
    // init info
    if (l == r) {
      // init info
      return;
    }
    int m = (l + r) / 2;
    build(L(id), l, m, ...);
    build(R(id), m + 1, r, ...);
    pull(id);
  }
  void upd(int id, int l, int r, int L, int R, ...) {
    if (l >= L && r <= R) {
      // update tags & info
      return;
    }
    int m = (l + r) / 2;
    push(id);
    if (L <= m) upd(L(id), l, m, L, R, ...);
    if (R > m) upd(R(id), m + 1, r, L, R, ...);
    pull(id);
  }
  int ask(int id, int l, int r, int L, int R, ...) {
    if (l >= L && r <= R) {
      // get info
    }
    int m = (l + r) / 2;
    push(id);
    int ans = 0;
    if (L <=
      m) // update ans = ask(L(id), l, m, L, R, ...);
      if (R > m) // update ans = ask(R(id), m + 1, r,
                 // L, R, ...);
        pull(id);
    // return ans
  }
} seg;