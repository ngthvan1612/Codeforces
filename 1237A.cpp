#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int N = 14000
int n, a[N], b[N]
int C(int x) { ///return ceil of x / 
  if (x % 2 == 0) return x / 2
  if (x > 0) return (x + 1) / 2
  return x / 2

int F(int x) 
  if (x % 2 == 0) return x / 2
  if (x > 0) return x / 2
  return (x - 1) / 2

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  int sum = 0
  for (int i = 1; i <= n; ++i) 
    cin >> a[i]
    b[i] = C(a[i])
    sum += b[i]
  
  for (int i = 1; i <= n; ++i) 
    if (a[i] % 2) 
      int diff = sum - b[i] + F(a[i])
      if (abs(diff) < abs(sum)) 
        sum = diff
        b[i] = F(a[i])
      
    
  
  for (int i = 1; i <= n; ++i
    cout << b[i] << '\n'
  return 0

