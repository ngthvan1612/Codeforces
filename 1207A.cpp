#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, b, p, f, h, c;
  for (cin >> t; t--;) {
    cin >> b >> p >> f;
    cin >> h >> c;
    if (h < c) {
      swap(h, c);
      swap(p, f);
    }
    int res1 = min(b / 2, p);
    b -= 2 * res1;
    int res2 = min(b / 2, f);
    cout << res1 * h + res2 * c << '\n';   
  }
  return 0;
}
