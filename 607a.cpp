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

const int N = 1e5 + 5;
ii a[N];
int n, dp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i].first >> a[i].second;
  sort(a + 1, a + 1 + n);
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    int k = lower_bound(a + 1, a + 1 + i, ii(a[i].first - a[i].second, -1)) - a;
    dp[i] = dp[k - 1] + i - k;
  }
  int res = dp[n];
  for (int i = 1; i <= n; ++i)
    res = min(res, dp[i - 1] + n - i + 1);
  cout << res;
  return 0;
}
