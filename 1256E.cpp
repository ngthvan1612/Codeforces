#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
typedef pair<int, int> ii;
int n, b[N], ans[N], rev[N], dp[N], sv[N];
ii a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  memset(dp, 0, sizeof dp);
  memset(sv, 0, sizeof sv);
  sv[0] = sv[1] = sv[2] = 1;
  for (int i = 3; i <= n; ++i) {
    dp[i] = a[i].first - a[1].first;
    rev[i] = 1;
    sv[i] = 1;
    if (sv[i - 2] >= 4) {
      if (dp[i] > a[i].first + dp[sv[i - 2] - 1] - a[sv[i - 2]].first) {
        dp[i] = a[i].first + dp[sv[i - 2] - 1] - a[sv[i - 2]].first;
        rev[i] = sv[i - 2];
      }
    }
    if (i >= 4) {
      if (dp[sv[i - 1] - 1] - a[sv[i - 1]].first < dp[i - 1] - a[i].first) {
        sv[i] = sv[i - 1];
      }
      else {
        sv[i] = i;
      }
    }
  }
  int cnt = 0, r = n;
  while (r >= 1) {
    ++cnt;
    for (int i = rev[r]; i <= r; ++i)
      ans[a[i].second] = cnt;
    r = rev[r] - 1;
  }
  printf("%d %d\n", dp[n], cnt);
  for (int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);
  return 0;
}
