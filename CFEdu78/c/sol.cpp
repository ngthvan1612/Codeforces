#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], n, l[N], r[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i)
      cin >> a[i];
    l[0] = r[2 * n + 1] = 0;
    for (int i = 1; i <= 2 * n; ++i)
      if (a[i] == 1) l[i] = l[i - 1] + 1;
      else l[i] = l[i - 1] - 1;
    for (int i = 2 * n; i >= 1; --i)
      if (a[i] == 1) r[i] = r[i + 1] + 1;
      else r[i] = r[i + 1] - 1;
    map<int, int> f;
    int ans = 1e9 + 7;
    for (int i = 0; i <= n; ++i)
      f[l[i]] = i;
    for (int i = n + 1; i <= 2 * n; ++i)
      if (f.find(-r[i]) != f.end()) {
        ans = min(ans, i - f[-r[i]] - 1);
      }      
    f.clear();
    for (int i = 2 * n + 1; i >= n + 1; --i)
      f[r[i]] = i;
    for (int i = 1; i <= n; ++i)
      if (f.find(-l[i]) != f.end()) {
        ans = min(ans, f[-l[i]] - i - 1);
      }
    cout << (ans == 1e9 + 7 ? 2 * n : ans) << '\n';
  }
  return 0;
}