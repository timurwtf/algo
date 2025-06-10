template <typename T>
vector<int> find_scc(const graph<T> &g) {
  vector<int> color(g.n, -1);
  vector<bool> used(g.n, 0);
  vector<int> order;
  int cnt = 0;

  graph<T> inv(g.n, 1);
  for (auto &e : g.edges) {
    inv.add(e.y, e.x, e.cost);
  }

  auto dfs1 = [&](auto&& self, int v) -> void {
    used[v] = 1;
    for (auto id : g.g[v]) {
      auto &e = g.edges[id];
      if (!used[e.y]) {
        self(self, e.y);
      }
    }
    order.push_back(v);
  };

  for (int i = 0; i < g.n; ++i) {
    if (!used[i]) {
      dfs1(dfs1, i);
    }
  }

  auto dfs2 = [&](auto&& self, int v) -> void {
    for (auto id : inv.g[v]) {
      auto &e = inv.edges[id];
      if (color[e.y] == -1) {
        color[e.y] = color[v];
        self(self, e.y);
      }
    }
  };

  for (int i = g.n - 1; i >= 0; --i) {
    int pos = order[i];
    if (color[pos] != -1) {
      continue;
    }
    color[pos] = cnt++;
    dfs2(dfs2, pos);
  }

  return color;
}