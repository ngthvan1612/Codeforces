#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int x[N], n, k;
vector<int> g[N];
bool vs[N];
bool w[N]; ///1->i

bool check(int a, int b) {
  if (!vs[a])
    return true;
  if (!vs[b])
    return true;
  if (lower_bound(g[b].begin(), g[b].end(), g[a][0]) == g[b].end())
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(vs, 0, sizeof vs);
  memset(w, 0, sizeof w);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> x[i];
    g[x[i]].push_back(i);
    vs[x[i]] = true;
  }
  typedef pair<int, int> ii;
  map<ii, int> mp;
  for (int i = 1; i <= n; ++i) {
    if (check(i, i))
      mp[ii(i, i)]++;
    if (i > 1 && check(i, i - 1))
      mp[ii(i, i - 1)]++;
    if (i > 1 && check(i - 1, i))
      mp[ii(i - 1, i)]++;
    if (i < n && check(i, i + 1))
      mp[ii(i, i + 1)]++;
    if (i < n && check(i + 1, i))
      mp[ii(i + 1, i)]++;
  }
  cout << mp.size() << '\n';
  cerr << clock();
  return 0;
}
