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

int n, x, d[101], h[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    cin >> n >> x;
    int mz = 0, p = -1;
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
      cin >> d[i] >> h[i];
      mz = max(mz, d[i]);
      if (d[i] > h[i]) {
        ok = true;
        if (p == -1) p = i;
        else {
          if (d[i] - h[i] > d[p] - h[p])
            p = i;
        }
      }
    }
    if (mz >= x) cout << 1;
    else {
      if (!ok) cout << -1;
      else {
        cout << 1 + (x - mz + d[p] - h[p] - 1) / (d[p] - h[p]);
      }
    }
    cout << '\n';
  }
  return 0;
}
