#include <bits/stdc++.h>

using namespace std;

int main() {
  int q, n, a, b, S;
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> q; q--;) {
    cin >> a >> b >> n >> S; ///[S - b, S]
    int x = min(a, S / n);
    int sum = x * n;
    if (S  - sum <= b) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
