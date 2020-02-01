#include <bits/stdc++.h>

using namespace std;

int main() {
  typedef long long ll;
  ll l, r, a = -1, b, c;
  cin >> l >> r;
  for (ll i = l; i <= r; ++i)
    for (ll j = i + 1; j <= r; ++j)
      for (ll k = j + 1; k <= r; ++k)
        if (__gcd(i, j) == 1 && __gcd(j, k) == 1 && __gcd(i, k) != 1) {
          a = i;
          b = j;
          c = k;
        }
  if (a < 0) cout << -1;
  else cout << a << ' ' << b << ' ' << c;
  return 0;
}
