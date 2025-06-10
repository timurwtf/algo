template <typename T>
class graph {
 public:
  struct edge {
    int x, y;
    T cost;
  };
  vector<vector<int>> g;
  vector<edge> edges;
  bool directed;
  int n;

  graph() : n(0) {}
  graph(int _n, bool _directed) : n(_n) {
    directed = _directed;
    g.resize(n);
  }

  void add(int x, int y, T cost = 1) {
    int id = (int) edges.size();
    if (directed) {
      g[x].push_back(id);
    } else {
      g[x].push_back(id);
      g[y].push_back(id);
    }
    edges.push_back({x, y, cost});
  }
};