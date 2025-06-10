template <typename T>
vector<int> find_bridges(const graph<T> &g) {
  vector<int> bridges;
  vector<int> tin(g.n, -1);
  vector<int> low(g.n, -1);
  int timer = 0;

  auto dfs = [&](auto&& self, int v, int p) -> void {
    tin[v] = low[v] = timer++;
    for (int id : g.g[v]) {
      auto &e = g.edges[id];
      int to = e.x ^ e.y ^ v;
      if (to == p) {
        continue;
      }
      if (tin[to] == -1) {
        self(self, to, v);
        low[v] = min(low[v], low[to]);
        if (low[to] > tin[v]) {
          bridges.push_back(id);
        }
      } else {
        low[v] = min(low[v], tin[to]);
      }
    }
  };

  for (int i = 0; i < g.n; ++i) {
    if (tin[i] == -1) {
      dfs(dfs, i, -1);
    }
  }

  return bridges;
}