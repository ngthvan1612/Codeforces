#include <bits/stdc++.h>

using namespace std;

int main() {
  typedef long long ll;
  vector<ll> f;
  for (int i = 1; i <= 9; ++i) {
    ll p = i;
    for (int j = 1; j <= 9; ++j) {
      f.push_back(p);
      p = p * 10 + i;
    }
  }
  sort(f.begin(), f.end());
  int t;
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    ll n, res = 0;
    cin >> n;
    for (int i = 0; i < int(f.size()); ++i)
      if (f[i] <= n) res++;
      else break;
    cout << res << '\n';
  }
  return 0;
}
