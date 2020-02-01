#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int oo = 1e9 + 7
const int N = 2e5 + 5
int n
ll b[N], a[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n / 2; ++i
    cin >> b[i]
  a[n + 1] = 1e18 + 9
  for (int i = 1; i <= n / 2; ++i) 
    int r = n - i + 1
    a[r] = min(b[i] - a[i - 1], a[r + 1])
    a[i] = b[i] - a[r]
  
  for (int i = 1; i <= n; ++i
    cout << a[i] << ' '
  return 0

