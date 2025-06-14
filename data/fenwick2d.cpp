template <typename T>
class FenwickTree2D {
 public:
  vector<vector<T>> fnw;
  int n, m;

  FenwickTree2D() : n(0), m(0) {}
  FenwickTree2D(int _n, int _m) : n(_n), m(_m) {
    fnw.assign(n, vector<T>(m, T()));
  }

  void Modify(int i, int j, T val) {
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fnw[x][y] += val;
        y |= y + 1;
      }
      x |= x + 1;
    }
  }

  T Query(int i, int j) {
    T res = T();
    int x = i;
    while (x >= 0) {
      int y = j;
      while (y >= 0) {
        res += fnw[x][y];
        y = (y & (y + 1)) - 1;
      }
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};