namespace matrix {

template <typename T>
vector<vector<T>> operator*(const vector<vector<T>> &a, const T lambda) {
  assert(!a.empty());
  vector<vector<T>> b(a.size(), vector<T>(a[0].size()));
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a[0].size(); ++j) {
      b[i][j] = a[i][j] * lambda;
    }
  }
  return b;
}

template <typename T>
vector<vector<T>> &operator*=(vector<vector<T>> &a, const T lambda) {
  return a = a * lambda;
}

template <typename T>
vector<vector<T>> operator+(const vector<vector<T>> &a, const vector<vector<T>> &b) {
  assert(!a.empty() && !b.empty());
  assert(a.size() == b.size() && a[0].size() == b[0].size());
  vector<vector<T>> c(a.size(), vector<T>(a[0].size()));
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a[0].size(); ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

template <typename T>
vector<vector<T>> &operator+=(vector<vector<T>> &a, const vector<vector<T>> &b) {
  return a = a + b;
}

template <typename T>
vector<vector<T>> operator*(const vector<vector<T>> &a, const vector<vector<T>> &b) {
  assert(!a.empty() && !b.empty());
  vector<vector<T>> c(a.size(), vector<T>(b[0].size()));
  for (int i = 0; i < (int) c.size(); ++i) {
    for (int j = 0; j < (int) c[0].size(); ++j) {
      c[i][j] = 0;
      for (int k = 0; k < (int) b.size(); ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

template <typename T>
vector<vector<T>> &operator*=(vector<vector<T>> &a, const vector<vector<T>> &b) {
  return a = a * b;
}

template <typename T>
vector<vector<T>> inverse(const vector<vector<T>> &a) {
  assert(!a.empty());
  vector<vector<T>> b(a[0].size(), vector<T>(a.size()));
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a[0].size(); ++j) {
      b[j][i] = a[i][j];
    }
  }
  return b;
}

template <typename T>
void debug(const vector<vector<T>> &a) {
  assert(!a.empty());
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a[0].size(); ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

} // namespace matrix

using namespace matrix;