#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, t;
char a[N], p[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> a + 1;
    n = int(strlen(a + 1));
    p[n + 1] = '\0';
    for (int i = n; i >= 1; --i)
      if (a[i] == '?') p[i] = p[i + 1];
      else p[i] = a[i];
    a[0] = '\0';
    for (int i = 1; i <= n; ++i) {
      if (a[i] == '?') {
        for (char w = 'a'; w <= 'c'; ++w)
          if (w != a[i - 1] && w != p[i])
            a[i] = w;
      }
    }
    bool ok = true;
    for (int i = 1; i <= n - 1; ++i)
      if (a[i] == a[i + 1]) {
        ok = false;
        break;
      }
    if (ok) cout << a + 1 << '\n';
    else cout << -1 << '\n';
  }
  return 0;
}
