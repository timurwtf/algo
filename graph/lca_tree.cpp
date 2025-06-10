template <typename T>
class lca_tree {
 public:
  vector<vector<int>> up;
  vector<int> depth, par;
  vector<bool> used;
  vector<int> tin, tout;
  int n, mxlog;

  lca_tree() : n(0) {}
  lca_tree(const graph<T> &g, int root) : n(g.n) {
    mxlog = __lg(n) + 1;
    up.assign(mxlog, vector<int>(n));
    depth.assign(n, -1);
    par.assign(n, -1);
    used.assign(n, false);
    tin.resize(n);
    tout.resize(n);
    int timer = 0;
    auto calc = [&](auto&& self, int v, int p, int d) -> void {
      depth[v] = d;
      par[v] = p;
      tin[v] = timer++;
      for (auto id : g.g[v]) {
        auto &e = g.edges[id];
        int to = e.x ^ e.y ^ v;
        if (to != p) {
          self(self, to, v, d + 1);
        }
      }
      tout[v] = timer++;
    };
    calc(calc, root, root, 0);
    for (int i = 0; i < n; ++i) {
      up[0][i] = par[i];
    }
    for (int j = 1; j < mxlog; ++j) {
      for (int i = 0; i < n; ++i) {
        up[j][i] = up[j - 1][up[j - 1][i]];
      }
    }
  }

  bool is_ancestor(int v, int u) {
    return (tin[v] <= tin[u] && tout[u] <= tout[v]);
  }

  int la(int v, int k) {
    k = min(k, depth[v]);
    for (int i = mxlog - 1; i >= 0; --i) {
      if (k & (1 << i)) {
        v = up[i][v];
      }
    }
    return v;
  }

  int lca(int v, int u) {
    if (depth[v] > depth[u]) {
      swap(v, u);
    }
    u = la(u, depth[u] - depth[v]);
    if (v == u) {
      return v;
    }
    for (int i = mxlog - 1; i >= 0; --i) {
      if (up[i][v] != up[i][u]) {
        v = up[i][v];
        u = up[i][u];
      }
    }
    return up[0][v];
  }
};