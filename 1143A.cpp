#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int N = 2e5 + 5
int n, a[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i
    cin >> a[i]
  int w = n
  while (w >= 1 && a[w] == a[n]
    w--
  cout << w; 
  return 0

