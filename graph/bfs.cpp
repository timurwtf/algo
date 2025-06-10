template <typename T>
vector<int> bfs(const graph<T> &g, int start) {
  T max_val = numeric_limits<int>::max();
  vector<int> dist(g.n, max_val);
  queue<int> q;

  dist[start] = 0;
  q.push(start);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto id : g.g[u]) {
      auto &e = g.edges[id];
      int v = e.x ^ e.y ^ u;
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
}