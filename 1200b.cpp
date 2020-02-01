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
  int t, h[101], n;
  ll m, k;
  for (cin >> t; t--;) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
      cin >> h[i];
    bool ok = true;
    for (int i = 1; i <= n - 1; ++i) {
      if (h[i + 1] >= h[i]) {
        int mz = h[i + 1] - k;
        if (h[i] >= mz) {
          int add = h[i] - max(0, mz);
          h[i] -= add;
          m += add;
        }
        else {
          if (h[i] + m >= mz) {
            m -= mz - h[i];
          }
          else {
            ok = false;
            break;
          }
        }
      }
      else {
        m += h[i] - h[i + 1];
        h[i] = h[i + 1];
        int add = h[i] - max(h[i] - k, 0LL);
        h[i] -= add;
        m += add;
      }
    }
    if (!ok) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}
