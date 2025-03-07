struct Tree {
  struct Edge {
    int from, to;
    ll cost;
    Edge() : from(-1), to(-1), cost(1ll) {}
    Edge(int x, int y, ll c) : from(x), to(y), cost(c) {}
    Edge inv() const {
      return Edge(to, from, cost);
    }
  };

  vector<int> depth, prev;
  vector<int> topsort, tin, tout, eulerian;
  vector<vector<Edge>> adj;
  int n;

  Tree() : Tree(0) {}
  Tree(int _n) : n(_n) {
    prev.assign(n, -1);
    depth.assign(n, -1);
    tin.assign(n, -1);
    tout.assign(n, -1);
    adj.resize(n);
  }

  void add_edge(int x, int y, ll c = 1) {
    adj[x].push_back(Edge(x, y, c));
    adj[y].push_back(Edge(y, x, c));
  }

  void add_dir_edge(int x, int y, ll c = 1) {
    adj[x].push_back(Edge(x, y, c));
  }

  void dfs(int v, int p = -1, int d = 0) {
    prev[v] = p;
    depth[v] = d;
    tin[v] = (int) eulerian.size();
    eulerian.push_back(v);
    for (auto e : adj[v]) {
      if (e.to == p) {
        continue;
      }
      dfs(e.to, v, d + 1);
      eulerian.push_back(v);
    }
    tout[v] = (int) eulerian.size();
    topsort.push_back(v);
  }

  bool is_ancestor(int x, int y) {
    return tin[x] < tin[y] && tout[x] > tout[y];
  }
};