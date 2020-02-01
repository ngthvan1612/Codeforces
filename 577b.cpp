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

const int N = 1e6 + 5;
const int M = 1e3 + 3;
int a[N], n, m, f[N];
int dp[M][M];
ii trace[M][M];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] %= m;
  }
  if (n >= m) {
    memset(f, -1, sizeof f);
    f[0] = 0;
    for (int i = 1, cur = 0; i <= n; ++i) {
      cur = (cur + a[i]) % m;
      if (f[cur] >= 0) {
        cout << "YES\n";
        return 0;
      }
      f[cur] = i;
    }
    assert(false);
  }
  else {
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int k = 0; k < m; ++k) {
        dp[i][k] = dp[i - 1][k];
        trace[i][k] = ii(i - 1, k);
        if (dp[i - 1][(k - a[i] + m) % m] >= 0) {
          dp[i][k] = dp[i - 1][(k - a[i] + m) % m] + 1;
          //trace[i][k] = ii(i - 1, (k - a[i] + m) % m);
        }
      }
    int wn = -1;
    for (int i = 1; i <= n; ++i)
      if (dp[i][0] >= 1)
        wn = i;
    if (wn > 0)
      cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
