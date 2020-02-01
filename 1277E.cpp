#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, a, b, cnt[4];
bool vs[N];

int dfs(int u, int& cnt) {
  int res = 0;
  vs[u] = 1;
  for (int v : g[u]) {
    if (v == a) res |= 1;
    if (v == b) res |= 2;
    if (!vs[v]) {
      cnt++;
      res |= dfs(v, cnt);      
    }
   }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      vs[i] = false;
    }
    vs[a] = vs[b] = true;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; ++i)
      if (!vs[i]) {
        int vt = 1;
        int type = dfs(i, vt);
        cnt[type] += vt;
      }
    cout << 1LL * cnt[1] * cnt[2] << '\n';
  }
  return 0;
}
