// implicit key treap
// range reversal + range sum
struct Treap {
  Treap *l, *r;
  int pri, size;
  int val, sum, rev;
  Treap(int _v)
    : l(nullptr), r(nullptr), pri(rng()), size(1),
      val(_v), sum(_v), rev(0) {}
};
int size(Treap *&rt) { return rt ? rt->size : 0; }
int sum(Treap *&rt) { return rt ? rt->sum : 0; }
void pull(Treap *&rt) {
  rt->size = 1 + size(rt->l) + size(rt->r);
  rt->sum = rt->val + sum(rt->l) + sum(rt->r);
}
void push(Treap *&rt) {
  if (rt->rev) {
    rt->rev = 0;
    swap(rt->l, rt->r);
    if (rt->l) rt->l->rev ^= 1;
    if (rt->r) rt->r->rev ^= 1;
  }
}
void split_size(
  Treap *rt, Treap *&a, Treap *&b, int k) {
  if (!rt) {
    a = b = nullptr;
    return;
  }
  push(rt);
  if (size(rt->l) >= k) {
    b = rt;
    split_size(rt->l, a, b->l, k);
    pull(b);
  } else {
    a = rt;
    split_size(rt->r, a->r, b, k - 1 - size(rt->l));
    pull(a);
  }
}
Treap *merge(Treap *a, Treap *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    push(a);
    a->r = merge(a->r, b);
    pull(a);
    return a;
  } else {
    push(b);
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}