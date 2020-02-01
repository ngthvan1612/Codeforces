#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
char a[205]
int n
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n >> a + 1
  int i = 1, ans = 0
  while (i <= n) 
    if ('A' <= a[i] && a[i] <= 'Z') ++i
    int j = i
    set<char> st
    while (j <= n && 'a' <= a[j] && a[j] <= 'z') 
      st.insert(a[j])
      ++j
    
    ans = max(ans, int(st.size()))
    i = j
  
  cout << ans << '\n'
  return 0

