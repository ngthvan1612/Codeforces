#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ma = 0, mi = 2e9, a, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    if (i > 1) {
      if (a < mi || a > ma) {
        ans++;
      }
    }
    mi = min(mi, a);
    ma = max(ma, a);
  }
  cout << ans;
  return 0;
}
