#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
int cnt[1000000];

bool isPrime(ll x) {
  for (ll i = 2; i * i <= x; ++i)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  cin >> n;
  vector<ll> fact;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0)
         n /= i;
    }
  if (n > 1) fact.push_back(n);
  sort(fact.begin(), fact.end());
  if (int(fact.size()) == 0) cout << n;
  else if (int(fact.size()) == 1) cout << fact[0];
  else cout << 1;
  return 0;
}
