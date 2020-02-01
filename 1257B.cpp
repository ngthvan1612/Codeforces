#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    ll x, y, f = 0, g = 0;
    cin >> x >> y;
    cerr <<" x, y = " << x << ", " << y << " -> ";
    while (x <= ll(1e12) && (f++ <= 100)) {
      g = max(g, x);
      if (x == 1) break;
      if (x % 2 == 0)
        x = 3LL * x / 2LL;
      else
        x--;
    }
    cerr << "g = " << g << '\n';
    cout << (g >= y ? "YES\n" : "NO\n");
  }
  return 0;
}
