#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int a[4][101], n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(a, -1, sizeof a);
  for (int i = 1; i <= min(m, 2 * n); ++i)
    if (i % 2)
      a[0][(i + 1) / 2] = i;
    else
      a[3][(i + 1) / 2] = i;
  for (int i = min(m, 2 * n) + 1; i <= m; ++i)
    if (i % 2)
      a[1][(i - min(m, 2 * n) + 1) / 2] = i;
    else
      a[2][(i - min(m, 2 * n) + 1) / 2] = i;
  int v[4] = { 1, 0, 2, 3 };
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j)
      if (a[v[j]][i] != -1)
        cout << a[v[j]][i] << ' ';
  return 0;
