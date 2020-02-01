#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, p, k, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0, pre = 0;
    for (int i = 1; i <= k + 1; ++i) {
      int sum = pre, res = 0, w = p;
      if (sum <= w) {
        res = i - 1;
        for (int j = i + k - 1; j <= n; j += k)
          if (sum + a[j] <= w) {
            sum += a[j];
            res += k;
          }
          else break;
        ans = max(ans, res);
      }
      pre += a[i];
    }
    cout << ans << '\n';
  }
  return 0;
