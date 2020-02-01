#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, a, b, x;
  for (cin >> t; t--;) {
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    int nb = min(x, n - b);
    b += nb;
    x -= nb;
    int na = min(x, a - 1);
    a -= na;
    x -= na;
    cout << b - a << '\n';
  }
  return 0;
}
