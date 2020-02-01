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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  for (cin >> q; q--;) {
    ll a[3], ans = 1e18, b[3], c[3];
    cin >> a[0] >> a[1] >> a[2];
    for (c[0] = -1; c[0] <= +1; ++c[0]) {
      for (c[1] = -1; c[1] <= +1; ++c[1]) {
        for (c[2] = -1; c[2] <= +1; ++c[2]) {
          for (int i = 0; i < 3; ++i)
            b[i] = a[i] + c[i];
          ans = min(ans, abs(b[0] - b[1]) + abs(b[1] - b[2]) + abs(b[2] - b[0]));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
