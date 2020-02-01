#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int a, b, c, r, u, v;
    cin >> a >> b >> c >> r;
    u = c - r;
    v = c + r;
    if (a > b) swap(a, b);
    if (u > b) u = b;
    if (u < a) u = a;
    if (v > b) v = b;
    if (v < a) v = a;
    cout << b - a + 1 - (v - u + 1) << '\n';
  }
  return 0;
}
