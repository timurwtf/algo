template<int Base>
struct ModularInteger {
  int x;

  ModularInteger() : x(0) {}
  ModularInteger(int _x) {
    _x %= Base;
    if (_x < 0) {
      _x += Base;
    }
    x = _x;
  }

  ModularInteger inv() const {
    return power(Base - 2);
  }

  ModularInteger &operator*=(const ModularInteger &rhs) {
    x = 1ll * x * rhs.x % Base;
    return *this;
  }

  ModularInteger &operator+=(const ModularInteger &rhs) {
    x += rhs.x;
    if (x >= Base) {
      x -= Base;
    }
    return *this;
  }

  ModularInteger &operator-=(const ModularInteger &rhs) {
    x -= rhs.x;
    if (x < 0) {
      x += Base;
    }
    return *this;
  }

  ModularInteger &operator/=(const ModularInteger &rhs) {
    return *this *= rhs.inv();
  }

  ModularInteger operator-() const {
    ModularInteger res;
    if (x == 0) {
      res.x = 0;
    } else {
      res.x = Base - x;
    }
    return res;
  }

  ModularInteger &operator++() {
    return *this += 1;
  }

  ModularInteger &operator--() {
    return *this -= 1;
  }

  friend ModularInteger operator*(ModularInteger lhs, const ModularInteger &rhs) {
    lhs *= rhs;
    return lhs;
  }

  friend ModularInteger operator+(ModularInteger lhs, const ModularInteger &rhs) {
    lhs += rhs;
    return lhs;
  }

  friend ModularInteger operator-(ModularInteger lhs, const ModularInteger &rhs) {
    lhs -= rhs;
    return lhs;
  }

  friend ModularInteger operator/(ModularInteger lhs, const ModularInteger &rhs) {
    lhs /= rhs;
    return lhs;
  }

  ModularInteger power(ll b) const {
    ModularInteger res = 1, a = ModularInteger(*this);
    while (b) {
      if (b & 1) {
        res *= a;
      }
      a *= a;
      b >>= 1;
    }
    return res;
  }

  friend istream &operator>>(istream &is, ModularInteger &a) {
    ll i;
    cin >> i;
    a = i;
    return is;
  }

  friend ostream &operator<<(ostream &os, const ModularInteger &a) {
    return os << a.x;
  }

  friend bool operator==(const ModularInteger &lhs, const ModularInteger &rhs) {
    return lhs.x == rhs.x;
  }

  friend bool operator<(const ModularInteger &lhs, const ModularInteger &rhs) {
    return lhs.x < rhs.x;
  }

  friend bool operator>(const ModularInteger &lhs, const ModularInteger &rhs) {
    return lhs.x > rhs.x;
  }

  friend bool operator<=(const ModularInteger &lhs, const ModularInteger &rhs) {
    return lhs.x <= rhs.x;
  }

  friend bool operator>=(const ModularInteger &lhs, const ModularInteger &rhs) {
    return lhs.x >= rhs.x;
  }

  bool operator!() const {
    return x == 0;
  }
};