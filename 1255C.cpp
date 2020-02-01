#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> ii;
#define fi first
#define se second
int n, cntz[N], p[N], ans[N];
bool mask[N];
vector<int> w[N];
map<ii, vector<int> > g;
map<ii, int> cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(cntz, 0, sizeof cntz);
  memset(mask, 0, sizeof mask);
  for (int i = 1; i <= n - 2; ++i) {
    int a[3];
    for (int j = 0; j < 3; ++j) {
      cin >> a[j];
      cntz[a[j]]++;
    }
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k)
        if (j != k) {
          w[a[j]].push_back(a[k]);
        }
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k)
        for (int z = 0; z < 3; ++z)
          if (z != j && z != k && j != k) {
            g[ii(a[j], a[k])].push_back(a[z]);
          }
  }
  for (int i = 1; i <= n; ++i)
    if (cntz[i] == 1)
      ans[1] = i;
  for (int e : w[ans[1]])
    if (cntz[e] == 2)
      ans[2] = e;
  mask[ans[1]] = mask[ans[2]] = true;
  for (int i = 3; i <= n; ++i) {
    for (int v : g[ii(ans[i - 2], ans[i - 1])]) {
      if (!mask[v]) {
        ans[i] = v;
        mask[v] = true;
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';
  return 0;
}
