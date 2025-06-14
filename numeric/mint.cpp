template <int B>
class MInt {
 public:
  int x;

  MInt() : x(0) {}
  MInt(long long _x) {
    _x %= B;
    if (_x < 0) {
      _x += B;
    }
    x = _x;
  }

  MInt power(long long b) const {
    MInt res = 1, a = *this;
    while (b) {
      if (b & 1) {
        res *= a;
      }
      a *= a;
      b >>= 1;
    }
    return res;
  }

  MInt inv() const {
    return power(B - 2);
  }

  MInt &operator*=(const MInt &other) {
    x = 1ll * x * other.x % B;
    return *this;
  }

  MInt &operator+=(const MInt &other) {
    x += other.x;
    if (x >= B) {
      x -= B;
    }
    return *this;
  }

  MInt &operator-=(const MInt &other) {
    x -= other.x;
    if (x < 0) {
      x += B;
    }
    return *this;
  }

  MInt &operator/=(const MInt &other) {
    return *this *= other.inv();
  }

  MInt operator-() const {
    MInt res;
    if (x == 0) {
      res.x = 0;
    } else {
      res.x = B - x;
    }
    return res;
  }

  MInt &operator++() {
    return *this += 1;
  }

  MInt &operator--() {
    return *this -= 1;
  }

  MInt operator++(int) {
    MInt tmp = *this;
    ++*this;
    return tmp; 
  }

  MInt operator--(int) {
    MInt tmp = *this;
    --*this;
    return tmp;
  }

  friend MInt operator*(MInt a, const MInt &b) {
    a *= b;
    return a;
  }

  friend MInt operator+(MInt a, const MInt &b) {
    a += b;
    return a;
  }

  friend MInt operator-(MInt a, const MInt &b) {
    a -= b;
    return a;
  }

  friend MInt operator/(MInt a, const MInt &b) {
    a /= b;
    return a;
  }

  friend istream &operator>>(istream &is, MInt &a) {
    long long i;
    cin >> i;
    a = i;
    return is;
  }

  friend ostream &operator<<(ostream &os, const MInt &a) {
    return os << a.x;
  }

  friend bool operator==(const MInt &a, const MInt &b) {
    return a.x == b.x;
  }

  friend bool operator<(const MInt &a, const MInt &b) {
    return a.x < b.x;
  }

  friend bool operator>(const MInt &a, const MInt &b) {
    return a.x > b.x;
  }

  friend bool operator<=(const MInt &a, const MInt &b) {
    return a.x <= b.x;
  }

  friend bool operator>=(const MInt &a, const MInt &b) {
    return a.x >= b.x;
  }

  bool operator!() const {
    return x == 0;
  }
};

const int md = $1;
using mint = MInt<md>;
