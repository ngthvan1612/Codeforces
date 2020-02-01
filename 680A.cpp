#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int cnt[101] = {0}, sum = 0, res = 0
  int n = 5
  for (int i = 1; i <= n; ++i) 
    int a
    cin >> a
    cnt[a]++
    sum += a
  
  for (int i = 100; i >= 1; --i
    if (cnt[i] >= 2
      res = max(res, min(3, cnt[i]) * i)
  cout << sum - res
  return 0

