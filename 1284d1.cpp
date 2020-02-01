#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e5 + 5;
struct dsu {
  int* d = NULL, n = 0;
  dsu(const int& _n = 0) {
    n = _n;
    d = new int[n + 1];
    for (int i = 1; i <= n; ++i)
      d[i] = i;
  }
  int Find(int u) {
    if (u == d[u])
      return d[u];
    return d[u] = Find(d[u]);
  }
  bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v)
      return false;
    d[u] = v;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}
