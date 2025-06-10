class dsu {
 public:
  vector<int> p, s;
  int n;

  dsu() : n(0) {}
  dsu(int _n) : n(_n) {
    p.resize(n);
    s.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int get(int x) {
    if (p[x] == x) {
      return x;
    }
    return p[x] = get(p[x]);
  }

  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return;
    }
    if (s[x] > s[y]) {
      swap(x, y);
    }
    s[y] += s[x];
    p[x] = y;
  }
};