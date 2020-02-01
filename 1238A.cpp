#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  typedef long long ll;
  int t;
  ll x, y;
  for (cin >> t; t--;) {
    cin >> x >> y;
    if (y != x - 1) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
