#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll S(ll x) {
  if (x < 10)
    return x;
  ll sum = 0;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return S(sum);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  for (cin >> n; n--;) {
    ll k, x;
    cin >> k >> x;
    cout << x + (k - 1) * 9 << '\n';
  }
  return 0;
}
