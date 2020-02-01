#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, c[2];
  for (cin >> t; t--;) {
    int n, ans = 0, cnt = 0, f[2] = {0}, odd = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      string a;
      cin >> a;
      if (a.length() % 2) {
        ans++;
        odd++;
        for (char w : a)
          f[w - '0']++;
      }
      else {
        c[0] = c[1] = 0;
        for (char w : a)
          c[w - '0']++;
        if (c[0] % 2) cnt++;
        else ans++;
      }
    }
    if (odd) ans = n;
    else ans += cnt / 2 * 2;
    cout << ans << '\n';
  }
  return 0;
}
