#include <bits/stdc++.h
using namespace std
const int N = 5e5 + 5
int a[N], n
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i
    cin >> a[i]
  sort(a + 1, a + 1 + n)
  int res = 0, j = n / 2
  for (int i = 1; i <= n / 2; ++i) 
    while (j <= n && 2 * a[i] > a[j]
      ++j
    if (2 * a[i] <= a[j]) 
      ++j
      res++
    
  
  cout << n -res
  return 0

