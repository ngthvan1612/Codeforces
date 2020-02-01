#include <bits/stdc++.h>

using namespace std;

int n, m, a[2005], b[2005], c[2005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];
  sort(b + 1, b + 1 + n);
  int ans = 1e9 + 7;
  for (int i = 1; i <= n; ++i) {
    bool ok = true;
    int x = ((b[1] - a[i]) % m + m) % m;
    for (int i = 1; i <= n; ++i)
      c[i] = (a[i] + x) % m;
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; ++i)
      if (c[i] != b[i]) {
        ok = false;
        break;
      }
    if (ok)
      ans = min(ans, x);
  }
  cout << ans;
  return 0;
}
