inline namespace Geometry {
  struct Point {
    ld x, y;
  
    explicit Point(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
    Point(Point a, Point b) { x = b.x - a.x, y = b.y - a.y; }
  
    bool operator==(const Point &other) const {
      return x == other.x && y == other.y;
    }
  
    Point operator+(const Point &other) const {
      return Point(x + other.x, y + other.y);
    }
  
    Point operator-(const Point &other) const {
      return Point(x - other.x, y - other.y);
    }
  
    Point operator*(ld k) const {
      return Point(x * k, y * k);
    }
  
    ld len() const {
      return sqrt(x * x + y * y);
    }
  
    ld operator*(const Point &other) const {
      return x * other.x + y * other.y;
    } // scalar multiplication
  
    ld operator%(const Point &other) const {
      return x * other.y - y * other.x;
    } // vector multiplication
  
    friend istream& operator>>(istream &is, Point &p) {
      is >> p.x >> p.y;
      return is;
    }
  
    friend ostream& operator<<(ostream &os, const Point &p) {
      os << p.x << " " << p.y;
      return os;
    }
  };
  
  ld angle(Point a, Point b) {
    if (atan2(a % b, a * b) < 0) {
      return atan2(a % b, a * b) + 2 * PI;
    }
    return atan2(a % b, a * b);
  }
  
  ld dist(Point a, Point b) {
    return Point(a, b).len();
  }
  
  bool eq(ld x, ld y) {
    return abs(x - y) < EPS;
  }
  } // namespace Geometry