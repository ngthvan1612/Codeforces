#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  string s
  char cur = 'a'
  int ans = 0
  cin >> s
  for (char c : s) 
    ans += min(abs(c - cur), 26 - abs(c - cur))
    cur = c
  
  cout << ans
  return 0

