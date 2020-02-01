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

const int N = 5e2 + 5;
int n, m, q, a[N][N], row[N];

int calc(int r) {
  int ans = 0;
  for (int j = 1; j <= m;) {
    if (a[r][j] == 0) { ++j; continue; }
    int i = j;
    while (i <= m && a[r][i] == 1) ++i;
    ans = max(ans, i - j);
    j = i;
  }
  return row[r] = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    calc(i);
  while (q--) {
    int u, v;
    cin >> u >> v;
    a[u][v] ^= 1;
    int res = calc(u);
    for (int i = 1; i <= n; ++i)
      res = max(res, row[i]);
    cout << res << '\n';
  }
  return 0;
}
