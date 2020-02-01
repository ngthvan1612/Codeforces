#include <bits/stdc++.h>

using namespace std;

int n, m, d, c[1003], ans[1003];
bool dp[1003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> d;
  int sum = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
    sum += c[i];
  }
  c[m + 1] = n - sum;
  int s = 0, cur = 0, i = 1;
  while (s < n && i <= m) {
    int jmp = 1;
    while (s + jmp - 1 + sum - cur < n && jmp < d) {
      jmp++;
    }
    for (int j = s + jmp + c[i] - 1; j >= s + jmp; --j) {
      ans[j] = i;
    }
    s += jmp + c[i] - 1;
    cur += c[i];
    ++i;
  }
  memset(dp, 0, sizeof dp);
  dp[0] = true;
  ans[n + 1] = 1;
  for (int i = 1; i <= n + 1; ++i)
    if (ans[i]) {
      for (int j = i - 1; j >= max(0, i - d); --j) {
        dp[i] |= dp[j];
      }
    }
  if (dp[n + 1]) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
      cout << ans[i] << ' ';
  }
  else cout << "NO";
  return 0;
}
