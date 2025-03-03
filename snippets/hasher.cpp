template<class Type, int Base>
struct Hasher {
  vector<Type> hash, pow;
  int n;

  Hasher(const string &s) {
    n = (int) s.size();
    hash.resize(n + 1, 0);
    pow.resize(n + 1, 1);
    for (int i = 0; i < n; ++i) {
      hash[i + 1] = hash[i] * Base + (s[i] - 'a' + 1);
      pow[i + 1] = pow[i] * Base;
    }
  }

  Type get(int l, int r) {
    Type result = hash[r] - hash[l] * pow[r - l];
    return result;
  }
};