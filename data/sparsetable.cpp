template <typename T, typename F>
class SparseTable {
 public:
  vector<vector<T>> matrix;
  vector<int> log;
  int n;
  F func;

  SparseTable(const vector<T> &a, const F &f) : func(f) {
    n = static_cast<int>(a.size());
    int mxlog = __lg(n) + 1;
    log.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      log[i] = log[i / 2] + 1;
    }
    matrix.assign(mxlog, vector<T>(n));
    for (int i = 0; i < n; ++i) {
      matrix[0][i] = a[i];
    }
    for (int j = 1; j < mxlog; ++j) {
      for (int i = 0; i + (1 << j) <= n; ++i) {
        matrix[j][i] = func(matrix[j - 1][i], matrix[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T Query(int l, int r) {
    int len = r - l, j = log[len];
    return func(matrix[j][l], matrix[j][r - (1 << j)]);
  }
};

/*
auto stfunc = [](const T &a, const T &b) {
  return F(a, b); // F = min, max, gcd, ...
};
SparseTable<T, decltype(stfunc)> st(vec, stfunc);
*/