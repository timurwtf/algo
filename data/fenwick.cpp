template <typename T>
class FenwickTree {
 public:
  vector<T> fnw;
  int n;

  FenwickTree() : n(0) {}
  FenwickTree(int _n) : n(_n) {
    fnw.resize(n + 1);
  }

  void Modify(int i, T val) {
    ++i;
    for (; i <= n; i += i & -i) {
      fnw[i] += val;
    }
  }

  T Prefix(int i) {
    ++i;
    T res = T();
    for (; i > 0; i -= i & -i) {
      res += fnw[i];
    }
    return res;
  }

  T Query(int l, int r) {
    return Prefix(r - 1) - Prefix(l - 1);
  }
};