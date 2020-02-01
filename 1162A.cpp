#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h, m, a[52];
  cin >> n >> h >> m;
  for (int i = 1; i <= n; ++i)
    a[i] = h;
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = l; i <= r; ++i)
      a[i] = min(a[i], x);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += a[i] * a[i];
   cout << ans;
  return 0;
}
