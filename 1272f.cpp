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

const int N = 2e2 + 5;
char s[N], t[N];
int n, m, dp[N][N][N];
struct elm {
  int i, j, bal;
  elm(int _i = 0, int _j = 0, int _bal = 0) {
    i = _i;
    j = _j;
    bal = _bal;
  }
};
elm trace[N][N][2 * N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s + 1 >> t + 1;
  n = int(strlen(s + 1));
  m = int(strlen(t + 1));
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= N - 1; ++i) {
    dp[0][0][i] = i;
    trace[0][0][i] = elm(0, 0, i - 1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int bal = 0; bal <= N - 1; ++bal) {
        int w = 0;
        ///...s[i]..t[j]
        
      }
    }
  }
  return 0;
}
