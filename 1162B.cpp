#include <bits/stdc++.h>

using namespace std;

int a[2][51][51];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int k = 0; k < 2; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> a[k][i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[0][i][j] > a[1][i][j])
        swap(a[0][i][j], a[1][i][j]);
  bool ok = true;
  for (int k = 0; k < 2; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (i > 1) {
          if (a[k][i][j] <= a[k][i - 1][j]) {
            ok = false;
          }
        }
        if (j > 1) {
          if (a[k][i][j] <= a[k][i][j - 1]) {
            ok = false;
          }
        }
      }
  cout << (ok ? "Possible" : "Impossible");
  return 0;
}
