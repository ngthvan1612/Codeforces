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

int n, m, a[101][101], r[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(a, 0, sizeof a);
  memset(r, 0, sizeof r);
  for (int i = 1; i <= m; ++i) {
    int win = 0;
    a[i][0] = -1;
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (a[i][win] < a[i][j]) {
        win = j;
      }
    }
    r[win]++;
  }
  int ans = 0;
  r[0] = -1;
  for (int i = 1; i <= n; ++i) {
    if (r[ans] < r[i]) {
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
