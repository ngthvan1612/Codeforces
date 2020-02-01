#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
const int modulo = 1e9 + 7;
template<typename T>
inline T sum(const T& a, const T& b) { return T((a % modulo + b % modulo) % modulo); }
template<typename T>
inline T mul(const T& a, const T& b) { return T((1LL * (a % (1LL * modulo)) * (b % (1LL * modulo))) % (1LL * modulo)); }
string to_string(string a) { return "\"" + a + "\""; }
#ifdef __LOCAL_DEBUG
#define debug(args...) { string __out = #args; replace(__out.begin(), __out.end(), ',', ' '); stringstream __out_ss(__out);\
istream_iterator<string> __it(__out_ss); _debug(__it, args); }
void _debug(istream_iterator<string> it) { }
template<typename T, typename... Args>
void _debug(istream_iterator<string> it, T a, Args... args){ cerr << *it << " = " << to_string(a) << '\n'; _debug(++it, args...); }
#else
#define debug(...)
#endif

const int N = 2e5 + 5;
int n, h[N], a, b, c, res, f[N];
bool mk[N];
vector<int> g[N];
vector<vector<ii> > w[N];

void dfs(int u, int p) {
  h[u] = 0;
  f[u] = u;
  vector<ii> tmp;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
      tmp.push_back(ii(h[v], v));
    }
  }
  sort(tmp.rbegin(), tmp.rend());
  if (int(tmp.size()) >= 1) {
    h[u] = tmp[0].first + 1;
    f[u] = f[tmp[0].second];
    if (h[u] >= res) {
      res = h[u];
      a = u;
      b = f[u];
    }
    if (int(tmp.size()) >= 2) {
      if (tmp[0].first + 1 + tmp[1].first + 1 >= res) {
        res = tmp[0].first + tmp[1].first + 2;
        a = f[tmp[0].second];
        b = f[tmp[1].second];
      }
    }
  }
  w[u].push_back(tmp);
}

bool dfs1(int u, int p) {
  if (u == b) {
    mk[u] = true;
    return true;
  }
  for (int v : g[u])
    if (v != p) {
      if (dfs1(v, u)) {
        mk[u] = true;
        return true;
      }
    }
  return false;
}

int dfs2(int u, int p) {
  int hi = 0;
  f[u] = u;
  for (int v : g[u])
    if (v != p && !mk[v]) {
      int cur = dfs2(v, u);
      if (hi <= cur) {
        hi = cur;
        f[u] = f[v];
      }
    }
  return hi + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(h, 0, sizeof h);
  memset(f, 0, sizeof f);
  a = b = -1;
  res = 0;
  dfs(1, 0);
  memset(mk, 0, sizeof mk);
  debug(a, b, res);
  dfs1(a, -1);
  int add = 0;
  memset(h, 0, sizeof h);
  for (int i = 1; i <= n; ++i) {
    if (mk[i]) {
      int cur = dfs2(i, -1);
      if (cur >= add) {
        add = cur;
        c = f[i];
      }
    }
  }
  debug(add);
  if (mk[c]) {
    for (int i = 1; i <= n; ++i)
      if (i != a && i != b)
        c = i;
  }
  cout << res + add - 1 << '\n' << a << ' ' << b << ' ' << c;
  return 0;
}
