#include <bits/stdc++.h
using namespace std
const int N = 1e5 + 5
int n
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  set<int> st
  for (int i = 1; i <= n; ++i) 
    int a
    cin >> a
    st.insert(a)
  
  if (int(st.size()) <= 2) cout << "YES\n"
  else if (int(st.size()) != 3) cout << "NO\n"
  else 
    int m[3], i = 0
    for (int x : st
      m[i++] = x
    if (m[1] * 2 == m[0] + m[2]) cout << "YES\n"
    else cout << "NO"
  
  return 0

