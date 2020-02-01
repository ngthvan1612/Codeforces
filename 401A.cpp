#include <bits/stdc++.h
using namespace std
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n, x, sum_pos = 0, sum_neg = 0
  cin >> n >> x
  while (n--) 
    int a
    cin >> a
    if (a > 0) sum_pos += a
    else sum_neg -= a
  
  int diff = abs(sum_pos - sum_neg)
  cout << diff / x + (diff % x != 0)
  return 0

