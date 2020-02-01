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

const int N = 2e4 + 5;
int n, t[N], g[N];

int solve(int w) {
  if (w < 3) return -1;
  int res = -oo, r = n / w;
  memset(g, 0, sizeof g);
  for (int i = 1; i <= n; ++i) {
    g[(i - 1) % r] += t[i];
  }
  for (int i = 0; i < r; ++i) {
    res = max(res, g[i]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    ans += t[i];
  }
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      if (i >= 3) {
        ans = max(ans, solve(i));
      }
      if (n / i >= 3) {
        ans = max(ans, solve(n / i));
      }
    }
  }
  cout << ans;
  return 0;
}
