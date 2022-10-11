struct PT {
  int x, y;
  PT() {}
  PT(int _x, int _y) : x(_x), y(_y) {}
};
PT operator+(const PT &p1, const PT &p2) {
  return PT(p1.x + p2.x, p1.y + p2.y);
}
PT operator-(const PT &p1, const PT &p2) {
  return PT(p1.x - p2.x, p1.y - p2.y);
}
int operator*(const PT &p1, const PT &p2) {
  return p1.x * p2.x + p1.y * p2.y;
}
int operator^(const PT &p1, const PT &p2) {
  return p1.x * p2.y - p1.y * p2.x;
}
PT perp(const PT &p) { return PT(-p.y, p.x); }
int sign(const int &x) {
  return x == 0 ? 0 : (x < 0 ? -1 : 1);
}
int abs2(const PT &x) { return x * x; }
double abs(const PT &x) { return sqrt(abs2(x)); }
int ori(PT p1, PT p2, PT p3) {
  return sign((p2 - p1) ^ (p3 - p1));
}
bool coline(PT p1, PT p2, PT p3) {
  return sign(ori(p1, p2, p3)) == 0;
}
bool btw(PT p1, PT p2, PT p3) {
  if (!coline(p1, p2, p3)) return false;
  return sign((p1 - p3) * (p2 - p3)) <= 0;
}
bool seg_inter(PT p1, PT p2, PT p3, PT p4) {
  int r123 = ori(p1, p2, p3);
  int r124 = ori(p1, p2, p4);
  int r341 = ori(p3, p4, p1);
  int r342 = ori(p3, p4, p2);
  if (r123 == 0 && r124 == 0) {
    return btw(p1, p2, p3) || btw(p1, p2, p4) ||
      btw(p3, p4, p1) || btw(p3, p4, p2);
  }
  return r123 * r124 <= 0 && r341 * r342 <= 0;
}