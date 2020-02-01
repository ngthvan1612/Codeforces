#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int mod = 1e9 + 7
int mul(const int& a, const int& b) 
  return int((1LL * a * b) % (1LL * mod))

int sum(const int& a, const int& b) 
  return (a + b) % mod

char a[105][105]
int n, m
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n >> m
  for (int i = 1; i <= n; ++i
    cin >> a[i] + 1
  int ans = 1
  for (int i = 1; i <= m; ++i) 
    int mask = 0
    for (int j = 1; j <= n; ++j
      mask |= (1 << (a[j][i] - 'A'))
    ans = mul(ans, __builtin_popcount(mask))
  
  cout << ans
  return 0

