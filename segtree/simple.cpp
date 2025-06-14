template <typename T>
class Tree {
 public:
  vector<T> info;
  int n;

  Tree(int size) {
    n = 1;
    while (n < size) {
      n <<= 1;
    }
    info.assign(2 * n, T());
  }

  void Modify(int i, const T &x, int v, int l, int r) {
    if (r - l == 1) {
      info[v] = x;
      return;
    }
    int mid = (l + r) >> 1;
    if (i < mid) {
      Modify(i, x, 2 * v + 1, l, mid);
    } else {
      Modify(i, x, 2 * v + 2, mid, r);
    }
    info[v] = info[2 * v + 1] + info[2 * v + 2];
  }

  void Modify(int i, const T &x) {
    Modify(i, x, 0, 0, n);
  }

  T Query(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
      return T();
    }
    if (ql <= l && r <= qr) {
      return info[v];
    }
    int mid = (l + r) >> 1;
    return Query(ql, qr, 2 * v + 1, l, mid) + Query(ql, qr, 2 * v + 2, mid, r);
  }

  T Query(int ql, int qr) {
    return Query(ql, qr, 0, 0, n);
  }
};
