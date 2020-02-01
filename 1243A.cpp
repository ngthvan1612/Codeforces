#include <bits/stdc++.h>

using namespace std;

int a[1001], n, k;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> k;
  for (int t = 0; t < k; ++t) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 1; i <= n; ++i)
      ans = max(ans, min(n - i + 1, a[i]));
    cout << ans << '\n';
  }
  return 0;
}
