#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int n, a[1005], l[1005], r[1005]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i
    cin >> a[i]
  a[0] = 0
  a[n + 1] = 1001
  for (int i = 1; i <= n; ++i
    l[i] = 1 + (a[i] >= a[i - 1]) * l[i - 1]
  for (int i = n; i >= 1; --i
    r[i] = 1 + (a[i] >= a[i + 1]) * r[i + 1]
  int ans = 0
  for (int i = 1; i <= n; ++i
    ans = max(ans, l[i] + r[i] - 1)
  cout << ans << '\n'
  return 0

