struct MCMF {
  struct Edge {
    int to, rev, cap, cost;
  };
  vector<Edge> g[MAXN];
  int dis[MAXN];
  int par[MAXN];
  int pid[MAXN];
  bool inq[MAXN];
  int n;

  void init(int _n) {
    n = _n;
    For(i, 0, n) g[i].clear();
  }
  void link(int u, int v, int cap, int cost) {
    g[u].push_back({v, sz(g[v]), cap, cost});
    g[v].push_back({u, sz(g[u]) - 1, 0, -cost});
  }
  pii maxFlow(int s, int t) {
    int flow = 0, cost = 0;
    while (true) {
      For(i, 0, n) {
        dis[i] = INF;
        inq[i] = false;
      }
      queue<int> que;
      que.push(s);
      dis[s] = 0;
      while (!que.empty()) {
        int now = que.front();
        que.pop();
        inq[now] = false;
        For(i, 0, sz(g[now]) - 1) {
          auto &e = g[now][i];
          if (e.cap > 0 &&
            e.cost + dis[now] < dis[e.to]) {
            dis[e.to] = dis[now] + e.cost;
            par[e.to] = now;
            pid[e.to] = i;
            if (!inq[e.to]) {
              inq[e.to] = true;
              que.push(e.to);
            }
          }
        }
      }
      if (dis[t] == INF) break;
      int mn = INF;
      for (int i = t; i != s; i = par[i]) {
        mn = min(mn, g[par[i]][pid[i]].cap);
      }
      flow += mn;
      cost += mn * dis[t];
      for (int i = t; i != s; i = par[i]) {
        g[par[i]][pid[i]].cap -= mn;
        g[i][g[par[i]][pid[i]].rev].cap += mn;
      }
    }
    return pii(flow, cost);
  }
} flow;