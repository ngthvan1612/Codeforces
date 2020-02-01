#include <bits/stdc++.h
using namespace std
const int N = 6e4 + 5
double esp = 1e-7
double x[N], v[N]
int n
bool check(double time) 
  double left = -1e9
  double right = +1e9
  for (int i = 1; i <= n; ++i) 
    left = max(left, x[i] - time * v[i])
    right = min(right, x[i] + time * v[i])
  
  return left <= right

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i
    cin >> x[i]
  for (int i = 1; i <= n; ++i
    cin >> v[i]
  double ll = 0.0, rr = 1e9, ans = 0.0
  for (int i = 0; i < 1024; ++i) 
    double mid = (ll + rr) / 2
    if (check(mid)) 
      ans = mid
      rr = mid - esp
    
    else ll = mid + esp
  
  printf("%0.15f\n", ans)
  return 0

