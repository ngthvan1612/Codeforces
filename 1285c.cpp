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
  ll x, ans = 1e15, a, b;
  cin >> x;
  vector<ll> f;
  ll z = x;
  for (ll i = 2; i * i <= z; ++i) {
    if (z % i == 0) {
      ll tmp = 1;
      while (z % i == 0) {
        tmp *= i;
        z /= i;
      }
      f.push_back(tmp);
    }
  }
  if (z > 1) f.push_back(z);
  int sz = int(f.size());
  for (int s = 0; s < (1 << sz); ++s) {
    ll ta = 1;
    for (int j = 0; j < sz; ++j) {
      if ((s >> j) & 1) {
        ta *= f[j];
      }
    }
    if (max(ta, x / ta) < ans) {
      ans = max(ta, x / ta);
      a = ta;
      b = x / ta;
    }
  }
  cout << a << ' ' << b;
  return 0;
}
