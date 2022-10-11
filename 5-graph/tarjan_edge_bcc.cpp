int d[MAXN];
int lo[MAXN];
vector<vector<int>> ebcc;
void getEBCC(int n, int p = 1, int dep = 1) {
  if (d[n]) return;
  static vector<int> st;
  d[n] = lo[n] = dep;
  int visp = 0;
  st.eb(n);
  for (auto &i : adj[n]) {
    if (i != n) {
      if (!visp && i == p) visp = 1;
      else if (d[i] != 0) lo[n] = min(lo[n], d[i]);
      else {
        dfs_ebcc(i, n, dep + 1);
        lo[n] = min(lo[n], lo[i]);
      }
    }
  }
  if (lo[n] == d[n]) { // edge BCC
    if (n != p) ans.eb(p, n); // !!!!
    ebcc.eb();
    do {
      ebcc.back().eb(st.back());
      st.pop_back();
    } while (ebcc.back().back() != n);
  }
}