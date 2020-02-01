#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, sl = 0, sr = 0;
  cin >> n;
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    sl += l;
    sr += r;
  }
  cout << min(sl, n - sl) + min(sr, n - sr);
  return 0;
}
