#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  string s
  int n
  cin >> n >> s
  bool ok = false
  for (int i = 1; i < n; ++i
    if (s[i] < s[i - 1]) 
      s[i - 1] = '.'
      ok = true
      break;     
    
  if (!ok) s[n - 1] = '.'
  for (char c : s
    if (c != '.'
      cout << c
  return 0

