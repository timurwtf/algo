template <typename T>
vector<T> dijkstra(const graph<T> &g, int start) {
  T max_val = numeric_limits<T>::max();
  vector<T> dist(g.n, max_val);
  set<pair<T, int>> s;

  dist[start] = 0;
  s.emplace(dist[start], start);

  while (!s.empty()) {
    int i = s.begin()->second;
    s.erase(s.begin());
    for (auto id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.x ^ e.y ^ i;
      if (dist[to] > dist[i] + e.cost) {
        s.erase({dist[to], to});
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }

  return dist;
}