#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    typedef long long ll;
    ll a, b, c;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    c = min(a, b);
    a -= c;
    b -= c;
    ll ans = 0;
    while (a != b) {
      
    }
  }
  return 0;
}