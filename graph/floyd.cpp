template <typename T>
vector<vector<T>> floyd(const graph<T> &g) {
  T max_val = numeric_limits<int>::max();
  vector<vector<T>> dist(g.n, vector<T>(g.n, max_val));

  for (int i = 0; i < g.n; ++i) {
    dist[i][i] = 0;
  }

  for (auto &e : g.edges) {
    dist[e.x][e.y] = min(dist[e.x][e.y], e.cost);
  }

  for (int k = 0; k < g.n; ++k) {
    for (int i = 0; i < g.n; ++i) {
      for (int j = 0; j < g.n; ++j) {
        if (dist[i][k] != max_val && dist[k][j] != max_val) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  return dist;
}