#include <bits/stdc++.h>

using namespace std;

int main() {
  typedef long long ll;
  ll n, cnt = 0;
  bool prime = true;
  cin >> n;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      prime = false;
      n -= i;
      cnt++;
      break;
    }
  if (prime) cout << 1;
  else cout << cnt + n / 2;
  return 0;
}
