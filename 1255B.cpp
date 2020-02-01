#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3 + 1;
int n, m;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  for (cin >> T; T--;) {
    cin >> n >> m;
    int sum = 0, a;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      sum += a;
    }
    if (n != m || n == 2) cout << -1 << '\n';      
    else {
      cout << 2 * sum << '\n';
      for (int i = 1; i <= n - 1; ++i)
        cout << i << ' ' << i + 1 << '\n';
      cout << n << ' ' << 1 << '\n';
    }
  }
  return 0;
