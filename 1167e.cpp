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

const int N = 1e6 + 7;
int n, x, a[N], mi[N], ma[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  memset(mi, -1, sizeof mi);
  memset(ma, -1, sizeof ma);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (mi[a[i]] == -1) mi[a[i]] = i;
    ma[a[i]] = i;
  }
  int l = 0, r = 0;
  mi[x + 1] = ma[x + 1] = oo;
  for (int i = x; i >= 1; --i) {
    if (mi[i] == -1) {
      mi[i] = ma[i] = mi[i + 1];
    }
    else {
      if (ma[i] > mi[i + 1])
        break;
    }
    r = i;
  }
  for (int i = 1; i <= x; ++i) {
    if (mi[i] == -1) {
      mi[i] = ma[i] = ma[i - 1];
    }
    else {
      if (mi[i] < ma[i - 1])
        break;
    }
    l = i;
  }
  debug(l, r);
  if (r < l) cout << 1LL * x * (x + 1) / 2;
  else {
    ///[1...l] -> [l+1...r-1] -> [r...x]
    ll ans = 0;
    ans += 1LL * (x - (r - 1) + 1) * (l + 1 - 1 + 1);
    cout << ans;
  }
  return 0;
}
