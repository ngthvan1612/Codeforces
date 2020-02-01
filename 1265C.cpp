#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef pair<int, int> ii;
const int N = 4e5 + 5;
int t, a[N], n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    vector<ii> p;
    a[n + 1] = -1;
    for (int i = 1, x = a[1], cnt = 0; i <= n + 1; ++i) {
      if (x != a[i]) {
        p.push_back(ii(x, cnt));       
        x = a[i];
        cnt = 1;
      }
      else cnt++;
    }
    int sz = n;
    while (sz > n / 2) {
      sz -= p.back().se;
      p.pop_back();
    }
    int g = 0, s = 0, b = 0;
    if (int(p.size()) >= 3) {
      g = p[0].se;
      int i = 1;
      while (s <= g && i < int(p.size())) {
        s += p[i].se;
        ++i;
      }
      while (i < int(p.size())) {
        b += p[i].se;
        ++i;
      }
      if (g < s && g < b)
        cout << g << ' ' << s << ' ' << b << '\n';
      else cout << "0 0 0\n";
    }
    else cout << "0 0 0\n";
  }
  return 0;
}
