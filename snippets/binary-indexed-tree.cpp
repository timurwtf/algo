template<class Type>
struct BIT {
  vector<Type> tree;
  int n;

  BIT(int _n = 0) : n(_n) {
    tree.assign(n + 1, Type());
  }

  void modify(int i, const Type &x) {
    ++i;
    for (; i <= n; i += i & -i) {
      tree[i] += x;
    }
  }

  Type prefix(int i) {
    ++i;
    Type res = Type();
    for (; i > 0; i -= i & -i) {
      res += tree[i];
    }
    return res;
  }

  Type query(int l, int r) {
    Type res = prefix(r - 1) - prefix(l - 1);
    return res;
  }
};