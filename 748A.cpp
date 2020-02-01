#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n, m, k
  cin >> n >> m >> k
  k--
  cout << (k + 2 * m) / (2 * m) << ' '
  cout << k % (2 * m) / 2 + 1 << ' '
  cout << (k % 2 ? "R" : "L")
  return 0

