template<class Type>
struct SegmentTree {
  vector<Type> tree;
  int n;

  SegmentTree() : SegmentTree(0) {}
  SegmentTree(int _n) : SegmentTree(vector<Type>(_n, Type())) {}
  SegmentTree(const vector<Type> &v) {
    n = (int) v.size();
    tree.assign(4 * n, Type());
    for (int i = 0; i < n; ++i) {
      modify(i, v[i]);
    }
  }

  void modify(int i, const Type &x, int v, int l, int r) {
    if (r - l == 1) {
      tree[v] = x;
      return;
    }
    int mid = (l + r) >> 1;
    if (i < mid) {
      modify(i, x, 2 * v + 1, l, mid);
    } else {
      modify(i, x, 2 * v + 2, mid, r);
    }
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  }

  void modify(int i, const Type &x) {
    modify(i, x, 0, 0, n);
  }

  Type range_query(int ql, int qr, int v, int l, int r) {
    if (qr <= l || r <= ql) {
      return Type();
    }
    if (ql <= l && r <= qr) {
      return tree[v];
    }
    int mid = (l + r) >> 1;
    return range_query(ql, qr, 2 * v + 1, l, mid) + range_query(ql, qr, 2 * v + 2, mid, r);
  }

  Type range_query(int ql, int qr) {
    return range_query(ql, qr, 0, 0, n);
  }

  Type query(int i) {
    return range_query(i, i + 1, 0, 0, n);
  }
};