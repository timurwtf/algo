template<typename Type>
struct Graph {
  struct Edge {
    int from, to;
    Type cost;
  };

  vector<vector<int>> g;
  vector<Edge> edges;
  int n;

  Graph(int _n) : n(_n) {
    g.resize(n);
  }
};