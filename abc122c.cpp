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
char a[N];
int n, q, dp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> a + 1;
  dp[0] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    dp[i] = dp[i - 1];
    if (a[i] == 'A' && a[i + 1] == 'C')
      dp[i]++;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[r - 1] - dp[l - 1] << '\n';
  }
  return 0;
}
