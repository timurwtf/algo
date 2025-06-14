template <typename T>
class FenwickTree {
 public:
  vector<T> fnw;
  int n;

  FenwickTree() : n(0) {}
  FenwickTree(int _n) : n(_n) {
    fnw.assign(n, T());
  }

  void Modify(int i, T val) {
    while (i < n) {
      fnw[i] += val;
      i |= i + 1;
    }
  }

  T Prefix(int i) {
    T res = T();
    while (i >= 0) {
      res += fnw[i];
      i = (i & (i + 1)) - 1;
    }
    return res;
  }

  T Query(int i, int j) {
    if (i == 0) {
      return Prefix(j - 1);
    } else {
      return Prefix(j - 1) - Prefix(i - 1);
    }
  }
};
