#include <bits/stdc++.h>

using namespace std;

const int hor[] = { +1, +1, +0, -1, -1, -1, +0, +1 }; ///x
const int ver[] = { +0, +1, +1, +1, +0, -1, -1, -1 }; ///y
const int N = 2e5 + 5;
int n, sx, sy, x[N], y[N];

bool inRange(int v, int low, int high) {
  int p = min(low, high);
  int q = max(low, high);
  return p <= v && v <= q;
}

int Count(int u, int v) {
  int res = 0;
  for (int i = 1; i <= n; ++i)
    if (inRange(u, x[i], sx) && inRange(v, y[i], sy))
      res++;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> sx >> sy;
  for (int i = 1; i <= n; ++i)
    cin >> x[i] >> y[i];
  int ans = 0, rx, ry;
  for (int i = 0; i < 8; ++i) {
    int u = hor[i] + sx;
    int v = ver[i] + sy;
    if (inRange(u, 0, int(1e9)) && inRange(v, 0, int(1e9))) {
      int E = Count(u, v);
      if (E >= ans) {
        ans = E;
        rx = u;
        ry = v;
      }
    }
  }
  cout << ans << '\n' << rx << ' ' << ry;
  return 0;
}
