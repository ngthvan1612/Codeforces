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
int n, h[N][2];
ll f[N][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int k = 0; k < 2; ++k)
    for (int i = 1; i <= n; ++i)
      cin >> h[i][k];
  memset(f, 0, sizeof f);
  f[1][0] = h[1][0];
  f[1][1] = h[1][1];
  for (int i = 2; i <= n; ++i) {
    f[i][0] = h[i][0] + max(f[i - 1][1], f[i - 1][2]);
    f[i][1] = h[i][1] + max(f[i - 1][0], f[i - 1][2]);
    f[i][2] = max(f[i - 1][0], max(f[i - 1][1], f[i - 1][2]));
  }
  cout << max(f[n][0], max(f[n][1], f[n][2]));
  return 0;
}
