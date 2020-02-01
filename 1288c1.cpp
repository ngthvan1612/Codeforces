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

const int N = 1e3 + 1;
const int M = 11;
int a[M][N], b[M][N];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  a[0][1] = 1;
  b[0][n] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= j; ++k)
        a[i][j] = sum(a[i][j], a[i - 1][k]);
    }
    for (int j = n; j >= 1; --j) {
      for (int k = n; k >= j; --k)
        b[i][j] = sum(b[i][j], b[i - 1][k]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      ans = sum(ans, mul(a[m][i], b[m][j]));
  cout << ans;
  return 0;
}
