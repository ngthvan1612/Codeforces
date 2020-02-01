#include <bits/stdc++.h
using namespace std
int main() 
  int q, n, a[101]
  for (cin >> q; q--;) 
    cin >> n
    int ans = 1
    for (int i = 1; i <= n; ++i
      cin >> a[i]
    sort(a + 1, a + 1 + n)
    for (int i = 1; i < n; ++i
      if (a[i + 1] - a[i] == 1) 
        ans = 2
        break
      
    cout << ans << '\n'
  
  return 0

