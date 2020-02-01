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
int cnt[N] = {0};
int n, m;

int dfs(int i, int j) {
  if (i == n + 1) cnt[j]++;
  else
    for (int k = 1; k <= m; ++k)
      dfs(i + 1, max(j, k));
}

double fpow(double a, int n) {
  if (n == 0) return 1.0;
  if (n == 1) return a;
  double tmp = fpow(a, n / 2);
  tmp *= tmp;
  if (n & 1) tmp *= a;
  return tmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15) << fixed;
  cin >> m >> n;
  double ans = 0.0;
  for (int i = 1; i <= m; ++i) {
    ans += 1.0 * i * fpow(1.0 * i / m, n) - 1.0 * i * fpow(1.0 * (i - 1) / m, n);
  }
  cout << ans;
  return 0;
}
