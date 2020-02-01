#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, cnt[2][256] = {0}, n, m;
  char a[105], b[105];
  for (cin >> t; t--;) {
    cin >> a + 1 >> b + 1;
    n = strlen(a + 1);
    m = strlen(b + 1);
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i)
      cnt[0][a[i]]++;
    for (int i = 1; i <= n - 1; ++i)
      cnt[1][b[i]]++;
    bool ans = false;
    for (int i = n; i <= m; ++i) {
      cnt[1][b[i]]++;
      bool ok = true;
      for (int i = 'a'; i <= 'z'; ++i)
        if (cnt[0][i] != cnt[1][i]) {
          ok = false;
          break;
        }
      if (ok) {
        ans = true;
        break;
      }
      cnt[1][b[i - n + 1]]--;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
