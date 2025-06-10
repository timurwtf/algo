template <typename T>
vector<int> find_cutpoints(const graph<T> &g) {
  vector<int> cutpoints;
  vector<int> tin(g.n, -1);
  vector<int> low(g.n, -1);
  vector<bool> used(g.n, false);
  int timer = 0;

  auto dfs = [&](auto&& self, int v, int p) -> void {
    used[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    bool is_cutpoint = false;
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      int to = e.x ^ e.y ^ v;
      if (to == p) {
        continue;
      }
      if (!used[to]) {
        self(self, to, v);
        low[v] = min(low[v], low[to]);
        children++;
        if (low[to] >= tin[v] && p != -1) {
          is_cutpoint = true;
        }
      } else {
        low[v] = min(low[v], tin[to]);
      }
    }
    if (p == -1 && children > 1) {
      is_cutpoint = true;
    }
    if (is_cutpoint) {
      cutpoints.push_back(v);
    }
  };

  for (int i = 0; i < g.n; ++i) {
    if (!used[i]) {
      dfs(dfs, i, -1);
    }
  }

  return cutpoints;
}