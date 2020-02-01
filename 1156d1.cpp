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
int n, d[2][N], sz[2][N];

int Find(int color, int u) {
  if (d[color][u] == u) return u;
  return d[color][u] = Find(color, d[color][u]);
}

bool Union(int color, int u, int v) {
  u = Find(color, u);
  v = Find(color, v);
  if (u == v) return false;
  sz[color][v] += sz[color][u];
  d[color][u] = v;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    d[0][i] = d[1][i] = i;
    sz[0][i] = sz[1][i] = 1;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    Union(c, u, v);
  }
  ll ans = 0;
  for (int u = 1; u <= n; ++u) {
    int t0 = Find(0, u), t1 = Find(1, u);
    if (t0 == u) ans += 1LL * sz[0][u] * (sz[0][u] - 1);
    if (t1 == u) ans += 1LL * sz[1][u] * (sz[1][u] - 1);
    ans += 1LL * (sz[0][t0] - 1) * (sz[1][t1] - 1);
  }
  cout << ans;
  return 0;
}
