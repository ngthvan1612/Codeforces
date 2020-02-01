#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int N = 1e5 + 5
int a[N], n
ll b[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i
    cin >> a[i]
  a[n + 1] = 0
  for (int i = 1; i <= n; ++i
    cout << a[i] + a[i + 1] << ' '
  return 0

