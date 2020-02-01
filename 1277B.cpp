#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  for (cin >> t; t--;) {
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int& x : a) {
      cin >> x;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int pr = 0;
      while (a[i] % 2 == 0) {
        if (mp[a[i]]) break;
        mp[a[i]] = 1;
        a[i] /= 2;
        pr++;
      }
      res += pr;
    }
    cout << res << '\n';
  }
  return 0;
}
