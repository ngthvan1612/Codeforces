#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
struct pt {
  int x, y;
  pt(const int& _x = 0, const int& _y = 0) {
    x = _x;
    y = _y;
  }
};
bool operator<(const pt& L, const pt& R) {
  return L.x < R.x || (L.x == R.x && L.y < R.y);
}

const int N = 2500 + 5;
int n;
pt a[N];

ll calc(int u) {
  ll c[4] = {0};
  for (int i = 1; i <= n; ++i) {
    if (u != i) {
      if (a[i].x < a[u].x && a[i].y > a[u].y)
        c[0]++;
      if (a[i].x > a[u].x && a[i].y > a[u].y)
        c[1]++;
      if (a[i].x < a[u].x && a[i].y < a[u].y)
        c[2]++;
      if (a[i].x > a[u].x && a[i].y < a[u].y)
        c[3]++;
    }
  }
  return c[1] * c[2] * c[3] * c[0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i)
    res += calc(i);
  cout << res;
  return 0;
}
