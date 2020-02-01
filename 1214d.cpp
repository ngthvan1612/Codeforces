#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e6 + 5;
const int hor[] = { +0, +1 };
const int ver[] = { +1, +0 };
int n, m, f[N], c[N];
bool vs[N];
char g[N];

bool dfs(int u, int v) {
  if (u == n - 1 && v == m - 1)
    return true;
  bool res = false;
  for (int k = 0; k < 2; ++k) {
    int x = u + hor[k], y = v + ver[k];
    if (x > n - 1 || y > m - 1)
      continue;
    if (f[x * m + y] < c[x * m + y] && !vs[x * m + y]) {
      vs[x * m + y] = true;
      res |= dfs(x, y);      
      if (res == true) {
        f[x * m + y]++;
        break;
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> g + i * m;
  memset(f, 0, sizeof f);
  memset(c, 0, sizeof c);
  for (int i = 0; i < n * m; ++i)
    if (g[i] == '.')
      c[i] = 1;
    else
      c[i] = 0;
  c[0] = oo;
  c[n * m - 1] = oo;
  int ans = 0;
  while (dfs(0, 0)) {
    memset(vs, 0, sizeof vs);
    vs[0] = true;
    ans++;
  }
  cout << ans;
  return 0;
}
