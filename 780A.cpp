#include <bits/stdc++.h
using namespace std
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n, ans = 0, cur = 0
  map<int, int> mp
  cin >> n
  for (int i = 1 ; i <= 2 * n; ++i) 
    int x
    cin >> x
    if (mp[x] == 1) 
      cur--
      mp[x]++;     
    
    else 
      cur++
      mp[x]++
    
    assert(mp[x] <= 2)
    ans = max(ans, cur)
  
  cout << ans << '\n'
  return 0

