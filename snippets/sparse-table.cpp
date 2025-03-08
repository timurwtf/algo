template<class Type>
struct SparseTable {
  vector<vector<Type>> table;
  vector<int> log;

  Type merge(Type &a, Type &b) {
    return ; // here you need to return F(a, b)
  }

  SparseTable(vector<Type> &v) {
    int n = (int) v.size();
    int mxlog = __lg(n) + 1;
    log.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      log[i] = log[i / 2] + 1;
    }
    table.assign(mxlog, vector<Type>(n));
    for (int i = 0; i < n; ++i) {
      table[0][i] = v[i];
    }
    for (int j = 1; j < mxlog; ++j) {
      for (int i = 0; i + (1 << j) <= n; ++i) {
        table[j][i] = merge(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  Type query(int l, int r) {
    int len = r - l, j = log[len];
    return merge(table[j][l], table[j][r - (1 << j)]);
  }
};
