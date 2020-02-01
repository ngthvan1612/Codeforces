#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
inline bool check(int v) 
  if (v < 0) return false
  int t = int(sqrt(v))
  return t * t == v

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n
  cin >> n
  vector<int> a(n)
  for (int &x : a
    cin >> x
  sort(a.rbegin(), a.rend())
  int ans = 0
  for (int x : a
    if (!check(x)) 
      ans = x
      break
    
  cout << ans
  return 0

