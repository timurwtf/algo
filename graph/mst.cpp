template <typename T>
vector<int> find_mst(const graph<T> &g, T &ans) {
  vector<int> order(g.edges.size());
  vector<int> mst;
  dsu d(g.n);
  ans = 0;

  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&g](int a, int b) {
    return g.edges[a].cost < g.edges[b].cost;
  });

  for (int id : order) {
    auto &e = g.edges[id];
    if (d.get(e.x) != d.get(e.y)) {
      d.unite(e.x, e.y);
      mst.push_back(id);
      ans += e.cost;
    }
  }

  return mst;
}