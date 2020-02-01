#include <bits/stdc++.h
using namespace std
const int N = 2e5 + 5
int q, n, p[N], ans[N], rev[N]
bool vs[N]
int dfs(int u, int key) 
  rev[u] = key
  vs[u] = 1
  if (!vs[p[u]]
    return dfs(p[u], key) + 1
  return 0

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  for (cin >> q; q--;) 
    cin >> n
    for (int i = 1; i <= n; ++i) 
      cin >> p[i]
      vs[i] = 0
    
    int k = 0
    for (int i = 1; i <= n; ++i) 
      if (!vs[i]) 
        ++k
        ans[k] = dfs(i, k) + 1
      
    
    for (int i = 1; i <= n; ++i
      cout << ans[rev[i]] << ' '
    cout << '\n'
  
  return 0

