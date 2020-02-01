#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, l, r, ans1, ans2, tmp;
  cin >> n >> l >> r;
  tmp = 1 << (l - 1); /// 2 ^ (l - 1)
  ans1 = tmp * 2 - 1 + n - l;
  tmp = 1 << (r - 1); ///2 ^ (r - 1)
  ans2 = tmp * 2 - 1 + (n - r) * tmp;
  cout << ans1 << ' ' << ans2;
  return 0;
}
