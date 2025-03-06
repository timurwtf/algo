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
  vector<vector<int>> up;
  vector<vector<Edge>> adj;
  int root, mxlog, n;

  Tree() : Tree(0) {}
  Tree(int _n) : n(_n) {
    prev.assign(n, -1);
    depth.assign(n, -1);
    tin.assign(n, -1);
    tout.assign(n, -1);
    adj.resize(n);
  }

  void clear() {
    prev.clear();
    depth.clear();
    topsort.clear();
    tin.clear();
    tout.clear();
    eulerian.clear();
    up.clear();
    adj.clear();
    root = 0, mxlog = 0, n = 0;
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

  void init_lca(int _root) {
    root = _root;
    dfs(root, root);
    mxlog = __lg(n) + 1;
    up.assign(mxlog, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      up[0][i] = prev[i];
    }
    for (int j = 1; j < mxlog; ++j) {
      for (int i = 0; i < n; ++i) {
        up[j][i] = up[j - 1][up[j - 1][i]];
      }
    }
  }

  int la(int x, int k) {
    k = min(k, depth[x]);
    for (int i = mxlog - 1; i >= 0; --i) {
      if (k & (1 << i)) {
        x = up[i][x];
      }
    }
    return x;
  }

  int lca(int x, int y) {
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    y = la(y, depth[y] - depth[x]);
    if (x == y) {
      return x;
    }
    for (int i = mxlog - 1; i >= 0; --i) {
      if (up[i][x] != up[i][y]) {
        x = up[i][x];
        y = up[i][y];
      }
    }
    return up[0][x];
  }
};