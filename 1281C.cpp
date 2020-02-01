#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
char a[9 * N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, x;
  typedef long long ll;
  const ll mod = 1e9 + 7;
  ll ans;
  for (cin >> t; t--;) {
    cin >> x >> a + 1;
    n = int(strlen(a + 1));
    bool ok = true;
    ans = n;
    for (int l = 0; l < x; ++l) {
      if (ok) {
        ///c = a[l+2...n]
        int tmp = n;
        for (int z = 1; z <= a[l + 1] - '0' - 1; ++z) {
          for (int i = l + 2; i <= tmp; ++i) {
            ++n;
            a[n] = a[i];
          }
        }
        if (n >= x) ok = false;
      }
      ll szs = l + 1;
      ll szc = ((ans - szs) % mod + mod) % mod;
      ans = (szs + szc * (a[l + 1] - '0')) % mod;
    }
//    cerr << "DEBUG: " << a << '\n';
    cout << ans << '\n';
  }
  return 0;
}
