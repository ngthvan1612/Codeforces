#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

char a[120][120];
int n, m, r[120] = {0}, c[120] = {0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i] + 1;
  int x[2], y[2];
  x[0] = y[0] = +oo;
  x[1] = y[1] = -oo;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] == 'B') {
        x[0] = min(x[0], i);
        y[0] = min(y[0], j);
        x[1] = max(x[1], i);
        y[1] = max(y[1], j);
      }
  cout << (x[0] + x[1]) / 2 << ' ' << (y[0] + y[1]) / 2 << '\n';
  return 0;
}
