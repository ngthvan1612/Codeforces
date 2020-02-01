#include <bits/stdc++.h
using namespace std
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n
  map<string, bool> mp
  for (cin >> n; n--;) 
    string name
    cin >> name
    if (mp[name]) cout << "YES\n"
    else cout << "NO\n"
    mp[name] = true
  
  return 0

