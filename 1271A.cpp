#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d, e, f, ans = 0;
  cin >> a >> b >> c >> d >> e >> f;
  for (int u = 0; u <= min(a, d); ++u) {
    ans = max(ans, u * e + min(b, min(d - u, c)) * f);
  }
  cout << ans;
  return 0;
}
