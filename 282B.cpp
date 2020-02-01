#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n, sum = 0, g = 0
  cin >> n
  vector<ii> a(n)
  for (ii &p : a) 
    cin >> p.first >> p.second
    sum += p.first
  
  while (g < n && abs(sum) > 500) sum -= 1000, g++
  if (abs(sum) > 500) cout << -1
  else 
    for (int i = 1; i <= g; ++i) cout << "G"
    for (int i = g + 1; i <= n; ++i) cout << "A"
  
  return 0

