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

ll solve() {
  int n;
  cin >> n;
  vector<ll> d(n);
  for (ll &x : d)
    cin >> x;
  sort(d.begin(), d.end());
  ll x = d[0] * d[n - 1];
  int i = 0, j = n - 1;
  while (i <= j) {
    if (d[i] * d[j] != x) {
      return -1;
    }
    ++i, --j;
  }
  vector<ll> w;
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    w.push_back(i);
    if (i * i != x)
      w.push_back(x / i);
  }
  sort(w.begin(), w.end());
  if (w != d)
    return -1;
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;)
    cout << solve() << '\n';
  return 0;
}
