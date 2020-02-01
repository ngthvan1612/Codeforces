#include <bits/stdc++.h>

using namespace std;

int q, n, a[101];
bool m[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> q; q--;) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    memset(m, 0, sizeof m);
    for (int i = 1; i <= n; ++i) {
      if (!m[i]) {
        int k = i;
        for (int j = i + 1; j <= n; ++j)
          if (a[k] > a[j])
            k = j;
        for (int j = k - 1; j >= i; --j) {
          m[j] = 1;
          swap(a[j], a[j + 1]);
        }
      }
    }
    for (int i = 1; i <= n; ++i)
      cout << a[i] << ' ';
    cout << '\n';
  }
  return 0;
}
