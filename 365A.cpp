#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int get_mask(int x) 
  int res = 0
  if (x == 0) res = 1
  while (x) 
    res |= (1 << (x % 10))
    x /= 10
  
  return res

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n, k, ans = 0, a, g
  cin >> n >> k
  g = (1 << (k + 1)) - 1
  for (int i = 1; i <= n; ++i) 
    cin >> a
    if ((get_mask(a) & g) == g
      ans++
  
  cout << ans
  return 0

