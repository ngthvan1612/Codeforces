#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    int n, ans = 0, mz = oo;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    reverse(a.begin(), a.end());
    for (int x : a) {
      if (x > mz) ans++;
      mz = min(mz, x);
    }
    cout << ans << '\n';
  }
  return 0;
}
