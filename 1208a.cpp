#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
const int mod = 2;

int mul(const int& a, const int& b) {
  return int(1LL * a * b % (1LL * mod));
}

map<int, int> F;

int f(int n) {
  if (F.count(n))
    return F[n];
  int k = n / 2;
  if (n % 2 == 0)
    return F[n] = (mul(f(k), f(k)) + mul(f(k - 1), f(k - 1))) % mod;
  return F[n] = (mul(f(k), f(k + 1)) + mul(f(k - 1), f(k))) % mod;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  F[0] = F[1] = 1;
  int t;
  for (cin >> t; t--;) {
    int a, b, n, ans = 0;
    cin >> a >> b >> n;
    if (n == 0) ans = a;
    else if (n == 1) ans = b;
    else if (n == 2) ans = a ^ b;
    else {
      if (f(n - 2)) ans ^= a;
      if (f(n - 1)) ans ^= b;
    }
    cout << ans << '\n';
  }
  return 0;
}
