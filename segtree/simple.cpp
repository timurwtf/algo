template <typename Info>
class SimpleSegmentTree {
 public:
  vector<Info> info;
  int n;

  SimpleSegmentTree() : n(0) {}
  SimpleSegmentTree(int _n) : SimpleSegmentTree(vector<Info>(_n)) {}

  SimpleSegmentTree(const vector<Info> &a) {
    n = static_cast<int>(a.size());
    info.resize(4 * n);
    auto Build = [&](auto&& self, int v, int l, int r) -> void {
      if (r - l == 1) {
        info[v] = a[l];
        return;
      }
      int mid = (l + r) >> 1;
      self(self, 2 * v + 1, l, mid);
      self(self, 2 * v + 2, mid, r);
      info[v] = info[2 * v + 1] + info[2 * v + 2];
    };
    Build(Build, 0, 0, n);
  }

  void Modify(int i, const Info &x, int v, int l, int r) {
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

  void Modify(int i, const Info &x) {
    Modify(i, x, 0, 0, n);
  }

  Info Query(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
      return Info();
    }
    if (ql <= l && r <= qr) {
      return info[v];
    }
    int mid = (l + r) >> 1;
    return Query(ql, qr, 2 * v + 1, l, mid) + Query(ql, qr, 2 * v + 2, mid, r);
  }

  Info Query(int ql, int qr) {
    return Query(ql, qr, 0, 0, n);
  }
};