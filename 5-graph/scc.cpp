int sccid[MAXN];
vector<vector<int>> scc;
void getSCC(int n) {
  memset(sccid, 0, sizeof(sccid));
  vector<int> st;
  auto dfs1 = [&](auto dfs, int cur) -> void {
    sccid[cur] = -1;
    for (auto &i : adj[cur]) {
      if (sccid[i] == 0) dfs(dfs, i);
    }
    st.eb(cur);
  };
  auto dfs2 = [&](auto dfs, int cur) -> void {
    scc.back().eb(cur);
    sccid[cur] = sz(scc) - 1;
    for (auto &i : rev[cur]) {
      if (sccid[i] == -1) dfs(dfs, i);
    }
  };
  For(i, 1, n) if (sccid[i] == 0) dfs1(dfs1, i);
  while (sz(st)) {
    if (sccid[st.back()] == -1) {
      scc.eb();
      dfs2(dfs2, st.back());
    }
    while (sz(st) && sccid[st.back()] != -1)
      st.pop_back();
  }
}