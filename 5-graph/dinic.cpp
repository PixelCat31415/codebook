struct Dinic {
  struct Edge {
    int to, rev, cap;
  };
  vector<Edge> g[MAXN];
  int d[MAXN], now[MAXN];
  int s, t;
  void init(int n) { For(i, 0, n - 1) g[i].clear(); }
  void link(int a, int b, int c) {
    g[a].push_back({b, sz(g[b]), c});
    g[b].push_back({a, sz(g[a]) - 1, 0});
  }
  bool bfs() {
    memset(d, -1, sizeof(d));
    d[s] = 0;
    queue<int> que;
    que.emplace(s);
    while (!que.empty()) {
      int k = que.front();
      que.pop();
      for (auto &e : g[k]) {
        if (d[e.to] != -1 || e.cap <= 0) continue;
        d[e.to] = d[k] + 1;
        que.emplace(e.to);
      }
    }
    return d[t] != -1;
  }
  int dfs(int k, int flow) {
    if (flow == 0 || k == t) return flow;
    for (int &i = now[k]; i < sz(g[k]); i++) {
      auto &e = g[k][i];
      if (d[e.to] != d[k] + 1 || e.cap <= 0) continue;
      int f = dfs(e.to, min(flow, e.cap));
      if (f) {
        e.cap -= f;
        g[e.to][e.rev].cap += f;
        return f;
      }
    }
    d[k] = -1;
    return 0;
  }
  int maxFlow(int _s, int _t) {
    s = _s;
    t = _t;
    int flow = 0, f;
    while (bfs()) {
      memset(now, 0, sizeof(now));
      while ((f = dfs(s, INF)) != 0) flow += f;
    }
    return flow;
  }
} flow;