#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
const double PI = acos(-1);
const double esp = 1e-5;

struct point {
  double x, y;
  point(const double& _x = 0, const double& _y = 0) {
    x = _x;
    y = _y;
  }
};

struct Vector {
  double u, v;
  Vector(const double& _u, const double& _v) {
    u = _u;
    v = _v;
  }
  Vector(const point& A, const point& B) {
    u = B.x - A.x;
    v = B.y - A.y;
  }
  double get_length() const {
    return sqrt(u * u + v * v);
  }
};

Vector operator+(const Vector& a, const Vector& b) {
  return Vector(a.u + b.u, a.v + b.v);
}

Vector operator-(const Vector& a, const Vector& b) {
  return Vector(a.u - b.u, a.v - b.v);
}

double dot(const Vector& a, const Vector& b) {
  return a.u * b.u + a.v * b.v;
}

double get_angle(const Vector& a, const Vector& b) {
  return acos(dot(a, b) / (a.get_length() * b.get_length()));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  point a[3];
  for (int i = 0; i < 3; ++i)
    cin >> a[i].x >> a[i].y;
  double ang[3];
  for (int i = 0; i < 3; ++i) {
    int u = (i - 1 + 3) % 3, v = (i + 1) % 3;
    ang[i] = get_angle(Vector(a[i], a[u]), Vector(a[i], a[v]));
  }
  double R = Vector(a[1], a[2]).get_length() / (2 * sin(ang[0]));
  for (int n = 3; n <= 100; ++n) {
    double alpha = (PI - 2 * PI / n) / (n - 2);
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
      double d = (ang[i] / alpha + esp);
      double id = int(d);
      if (abs(d - id) > 5 * esp) {
        ok = false;
      }
    }
    if (ok) {
      printf("%0.20f\n", 1.0 * n * 0.5 * R * R * sin(2 * PI / n));
      return 0;
    }
  }
  return 0;
}
