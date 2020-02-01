#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m;
struct pt {
  int a, b;
  pt(int _a = 0, int _b = 0) {
    a = _a;
    b = _b;
  }
};
bool operator<(const pt& l, const pt& r) {
  return (l.a < r.a) || (l.a == r.a && l.b < r.b);
}
pt p[N], tmp[N];

bool check(int k) {
  for (int i = 1; i <= m; ++i) {
    tmp[i] = pt((p[i].a - 1 + k) % n + 1, (p[i].b - 1 + k) % n + 1);
    if (tmp[i].a > tmp[i].b)
      swap(tmp[i].a, tmp[i].b);
  }
  sort(tmp + 1, tmp + 1 + m);
  for (int i = 1; i <= m; ++i)
    if (tmp[i].a != p[i].a || tmp[i].b != p[i].b)
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> p[i].a >> p[i].b;
    if (p[i].a > p[i].b)
      swap(p[i].a, p[i].b);
  }
  sort(p + 1, p + 1 + m);
  bool ans = false;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (check(i)) { ans = true; break; }
      if (i != 1 && check(n / i)) { ans = true; break; }
    }
  }
  if (ans)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
