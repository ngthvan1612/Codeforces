#include <bits/stdc++.h
using namespace std
typedef long long ll
const int N = 1e5 + 5
ll p[40]
bool dp[N]
int q
ll f(ll n) 
  if (n == 1
    return 0
  if (n % 2 == 0
    return 3 * f(n / 2) + 2
  els
    return 3 * f(n / 2 + 1)

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  p[0] = 1
  for (cin >> q; q--;) 
    ll n, L = 1, R = 1e12, res = 0
    cin >> n
    while (L <= R) 
      ll mid = (L + R) / 2
      if (f(mid) >= 2 * n) 
        res = mid
        R = mid - 1
      
      else L = mid + 1
    
    cout << f(res) / 2 << '\n'
  
  return 0

