bool upperhalf(const PT &p) {
  return p.y > 0 || (p.y == 0 && p.x >= 0);
}
bool pollarCmp(const PT &p1, const PT &p2) {
  auto u1 = upperhalf(p1);
  auto u2 = upperhalf(p2);
  if (u1 != u2) return u1;
  auto cr = ori(PT(0, 0), p1, p2);
  if (cr != 0) return cr > 0;
  return abs2(p1) < abs2(p2);
}