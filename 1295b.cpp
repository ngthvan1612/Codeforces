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
  int t;
  for (cin >> t; t--;) {
    int n, x;
    string s;
    cin >> n >> x >> s;
    s = "." + s;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      f[i] = f[i - 1];
      if (s[i] == '1') f[i]--;
      else f[i]++;
    }
    int d = f[n] - f[0];
    if (d == 0) {
      bool inf = false;
      for (int i = 0; i <= n; ++i)
        if (f[i] == x) {
          inf = true;
        }
      if (inf) cout << -1 << '\n';
      else cout << 0 << '\n';
    }
    else {
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        int w = x - f[i];
        if (w % d == 0 && w / d >= 0) {
          ans++;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
