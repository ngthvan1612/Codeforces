#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int a
  cin >> a
  vector<ll> f
  for (int i = 1; i <= 6; ++i) 
    for (int s = 0; s < (1 << (2 * i)); ++s
      if (__builtin_popcount(s) == i) 
        ll x = 0
        for (int j = 0; j < 2 * i; ++j
          if (s & (1 << j)
            x = x * 10 + 4
          els
            x = x * 10 + 7
        f.push_back(x)
      
  
  sort(f.begin(), f.end())
  for (ll x : f
    if (x >= a) 
      cout << x << '\n'
      break
    
  return 0

