#include <bits/stdc++.h
using namespace std
const int N = 2e2 + 5
int q, n, p[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  for (cin >> q; q--;) 
    cin >> n
    for (int i = 1; i <= n; ++i
      cin >> p[i]
    for (int i = 1; i <= n; ++i) 
      int z = i, res = 0
      do 
        z = p[z]
        res++
      } while (z != i)
      cout << res << ' '
    
    cout << '\n'
  
  return 0

