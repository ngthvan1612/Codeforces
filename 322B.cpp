#include <bits/stdc++.h
using namespace std
typedef long long ll
int main() 
  ll r, g, b, res
  cin >> r >> g >> b
  res = r / 3 + g / 3 + b / 3
  for (int i = 0; i < min(3LL, min(r, min(g, b))); ++i) 
    res = max(res, i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3)
  
  cout << res
  return 0

