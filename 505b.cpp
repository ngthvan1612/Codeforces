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

const int N = 1e2 + 5;
int d[N][N];
int n, m, q;

int Find(int w, int u) {
  if (d[w][u] == u) return u;
  return d[w][u] = Find(w, d[w][u]);
}

bool Union(int w, int u, int v) {
  u = Find(w, u);
  v = Find(w, v);
  if (u == v) return false;
  d[w][u] = v;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      d[i][j] = j;
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    Union(c, a, b);
  }
  cin >> q;
  while (q--) {
    int u, v, ans = 0;
    cin >> u >> v;
    for (int i = 1; i <= m; ++i) {
      if (Find(i, u) == Find(i, v))
        ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
