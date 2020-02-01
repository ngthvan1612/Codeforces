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

bool vs[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  typedef pair<ll, ll> il;
  vector<il> f;
  ll x = x0, y = y0;
  while (x <= 3e16 && y <= 3e16) {
    f.push_back(il(x, y));
    x = ax * x + bx;
    y = ay * y + by;
  }
  int m = int(f.size());
  debug(m);
  assert(m <= 100);
  ll ans = 0;
  ll xs, ys, t;
  cin >> xs >> ys >> t;
  for (int i = 0; i < m; ++i) {
    memset(vs, 0, sizeof vs);
    ll tx = xs, ty = ys, tt = t, tmp = 0;
    bool fi = true;
    while (t) {
      ll r = -1, w = 0;
      if (fi) { r = i; fi = false; }
      else
      for (int j = 0; j < m; ++j) {
        if (!vs[j]) {
          if (r == -1) r = j;
          else {
            ll tmp_u = abs(tx - f[j].first) + abs(ty - f[j].second);
            ll tmp_v = abs(tx - f[r].first) + abs(ty - f[r].second);
            if (tmp_u < tmp_v)
              r = j;
          }
        }
      }
      if (r == -1) break;
      w = abs(tx - f[r].first) + abs(ty - f[r].second);
      if (w > tt) break;
      vs[r] = true;
      tt -= w;
      tmp++;
      tx = f[r].first;
      ty = f[r].second;
    }
    ans = max(ans, tmp);
  }
  cout << ans;
  return 0;
}
