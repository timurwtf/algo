template<class Type>
struct Combinatorics {
  vector<Type> fac;

  Combinatorics(int _n) {
    fac.assign(_n + 1, 1);
    for (int i = 1; i < _n + 1; ++i) {
      fac[i] = fac[i - 1] * i;
    }
  }

  Type A(int n, int k) {
    return fac[n] / fac[n - k];
  }

  Type C(int n, int k) {
    return fac[n] / (fac[k] * fac[n - k]);
  }

  Type Cp(int n, int k) {
    return C(n + k - 1, k);
  }
};