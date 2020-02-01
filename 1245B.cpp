#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int n, r, p, s, win = 0;
    string a;
    cin >> n >> r >> p >> s;
    cin >> a;
    string ans(n, char(0));
    for (int i = 0; i < n; ++i) {
      if (a[i] == 'R') {
        if (p) {
          p--;
          ans[i] = 'P';
          win++;
        }
      }
      else if (a[i] == 'P') {
        if (s) {
          s--;
          ans[i] = 'S';
          win++;
        }
      }
      else if (a[i] == 'S') {
        if (r) {
          r--;
          ans[i] = 'R';
          win++;
        }
      }
    }
    if (win >= (n + 1) / 2) {
      for (int i = 0; i < n; ++i)
        if (ans[i] == char(0)) {
          if (r) ans[i] = 'R', r--;
          else if (p) ans[i] = 'P', p--;
          else ans[i] = 'S', s--;
        }
      cout << "YES\n" << ans << '\n';
    }
    else cout << "NO\n";
  }
  return 0;
}
