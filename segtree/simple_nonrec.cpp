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

  void Modify(int i, T x) {
    i += n;
    info[i] = x;
    for (i >>= 1; i >= 1; i >>= 1) {
      info[i] = info[2 * i] + info[2 * i + 1];
    }
  }

  T Query(int l, int r) {
    l += n;
    r += n;
    T res = T();
    while (l < r) {
      if (l & 1) {
        res = res + info[l];
        l++;
      }
      if (r & 1) {
        r--;
        res = res + info[r];
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};