template <typename T, int P>
class hasher {
 public:
  vector<T> hash, power;
  int n;

  hasher(const string &s) {
    n = static_cast<int>(s.size());
    hash.assign(n + 1, T());
    power.assign(n + 1, T(1));
    for (int i = 0; i < n; ++i) {
      hash[i + 1] = hash[i] * P + (s[i] - 'a' + 1);
      power[i + 1] = power[i] * P;
    }
  }

  T query(int l, int r) {
    return hash[r] - hash[l] * power[r - l];
  }
};

const int hp = $1;
using hash = hasher<$2, hp>;