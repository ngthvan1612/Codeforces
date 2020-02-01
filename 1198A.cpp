#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef pair<int, int> ii;
typedef long long ll;

const int N = 4e5 + 5;
int n, a[N], I, p[31], m, dp[N];
ii f[N];

int main() {
  scanf("%d %d", &n, &I);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  m = 0;
  f[m].fi = -1;
  for (int i = 1; i <= n; ++i)
    if (a[i] == f[m].fi) f[m].se++;
    else f[++m] = ii(a[i], 1);
  dp[0] = 0;
  for (int i = 1; i <= m; ++i)
    dp[i] = dp[i - 1] + f[i].se;
  int ans = 1e9 + 7;
  for (int i = 1; i <= m; ++i) {
    int K = 1; /// {a[1] -> a[i]} -> a[i]
    int l = i, r = m, res = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      //// {a[r] -> a[n]} -> a[r]
      ll need = 1LL * n * ll(ceil(log2(1.0 + 1 + (mid - 1) - (i + 1) + 1)));
      if (need <= 1LL * I * 8) {
        l = mid + 1;
        res = mid;
      }
      else {
        r = mid - 1;
      }
    }
    if (res > 0) {
      ans = min(ans, dp[m] - dp[res] + dp[i - 1]);
    }
  }
  printf("%d", ans);
  return 0;
}
