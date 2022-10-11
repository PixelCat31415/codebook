vector<PT> convex(vector<PT> v) {
  sort(all(v), [&](const PT &a, const PT &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  });
  vector<PT> hull;
  For(phase, 0, 1) {
    int t = sz(hull);
    for (auto &p : v) {
      int s = sz(hull);
      while (s - t >= 2 &&
        ori(hull[s - 2], hull[s - 1], p) <= 0) {
        hull.pop_back();
        s--;
      }
      hull.emplace_back(p);
    }
    hull.pop_back();
    reverse(all(v));
  }
  return hull;
}