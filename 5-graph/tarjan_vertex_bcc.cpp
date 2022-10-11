int d[MAXN];
int lo[MAXN];
bitset<MAXN> isap;
vector<vector<int>> vbcc;
void getVBCC(int n, int p, int dep = 1) {
  if (d[n]) return;
  static vector<int> st;
  d[n] = lo[n] = dep;
  int visp = 0, nc = 0;
  st.eb(n);
  for (auto &i : adj[n])
    if (i != n) {
      if (!visp && i == p) visp = 1;
      else if (d[i] != 0) lo[n] = min(lo[n], d[i]);
      else {
        nc++;
        dfs_vbcc(i, n, dep + 1);
        lo[n] = min(lo[n], lo[i]);
        if (n != p && lo[i] >= d[n]) isap[n] = 1;
        if (lo[i] >= d[n]) { // vertex BCC
          vbcc.eb();
          do {
            vbcc.back().eb(st.back());
            st.pop_back();
          } while (vbcc.back().back() != i);
          vbcc.back().eb(n);
        }
      }
    }
  if (n == p && nc > 1) isap[n] = 1;
}