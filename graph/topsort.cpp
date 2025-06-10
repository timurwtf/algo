template <typename T>
vector<int> find_topsort(const graph<T> &g) {
  vector<int> in_deg(g.n);
  vector<int> topsort;
  queue<int> q;
  int proc = 0;

  for (auto &e : g.edges) {
    in_deg[e.y]++;
  }

  for (int i = 0; i < g.n; ++i) {
    if (!in_deg[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topsort.push_back(u);
    proc++;
    for (auto id : g.g[u]) {
      int v = g.edges[id].y;
      if (!--in_deg[v]) {
        q.push(v);
      }
    }
  }

  if (proc != g.n) {
    return {};
  }

  return topsort;
}