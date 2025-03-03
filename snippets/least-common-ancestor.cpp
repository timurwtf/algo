struct LeastCommonAncestor {
  vector<vector<int>> up;
  vector<int> depth, prev;
  int n, mxlog;

  LeastCommonAncestor(const vector<vector<int>> &g, int r) {
    n = (int) g.size();
    mxlog = __lg(n) + 1;
    depth.assign(n, -1);
    prev.assign(n, -1);
    lca_dfs(r, r, 0, g);
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

  void lca_dfs(int v, int p, int d, const vector<vector<int>> &g) {
    depth[v] = d;
    prev[v] = p;
    for (auto to : g[v]) {
      if (to != p) {
        lca_dfs(to, v, d + 1, g);
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