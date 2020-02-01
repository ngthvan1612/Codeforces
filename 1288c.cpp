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

const int N = 1e3 + 3;
const int M = 10 + 3;
int n, m, f[M][N][N], g[M][N][N];

int sub(int a, int b) {
  a %= modulo;
  b %= modulo;
  a -= b;
  if (a < 0) a += modulo;
  return a;
}

int dfs(int i, int j, int k) {
  int &res = f[i][j][k];
  if (res > -1)
    return res;
  if (i == m)
    return res = (j <= k);
  res = 0;
  for (int u = j; u <= n; ++u)
    for (int v = u; v <= k; ++v)
      res = sum(res, dfs(i + 1, u, v));
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(f, 0, sizeof f);
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k <= n; ++k) {
        if (i == 1) f[i][j][k] = 1;
        else {
          int r = 0;
          r = sum(r, g[i - 1][j][n]);
          r = sub(r, g[i - 1][j][k - 1]);
          r = sub(r, g[i - 1][0][n]);
          r = sum(r, g[i - 1][0][k - 1]);
          ///sum f[1..j][k...n]
          f[i][j][k] = r;
        }
        if (i == m)
          res = sum(res, f[i][j][k]);
      }
    }
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        g[i][j][k] = f[i][j][k];
        g[i][j][k] = sum(g[i][j][k], g[i][j - 1][k]);
        g[i][j][k] = sum(g[i][j][k], g[i][j][k - 1]);
        g[i][j][k] = sub(g[i][j][k], g[i][j - 1][k - 1]);
      }
    }
  }
  cout << res;
  return 0;
}
