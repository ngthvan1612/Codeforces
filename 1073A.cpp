#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n
  cin >> n
  string s
  cin >> s
  for (int i = 0; i < int(s.length()) - 1; ++i
    if (s[i] != s[i + 1]) 
      cout << "YES\n" << s[i] << s[i + 1]
      return 0
    
  cout << "NO\n"
  return 0

