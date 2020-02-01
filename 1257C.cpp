#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int t, n, a[N], prv[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      prv[a[i]] = 0;
    }
    int ans = 1e9 + 7;
    for (int i = 1; i <= n; ++i) {
      if (prv[a[i]])
        ans = min(ans, i - prv[a[i]] + 1);
      prv[a[i]] = i;
    }
    cout << (ans == 1e9 + 7 ? -1 : ans) << '\n';
  }
  return 0;
}
