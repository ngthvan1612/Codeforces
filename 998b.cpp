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

int n, b, a[105];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> b;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int dp = 0;
  vector<int> f;
  for (int i = 1; i <= n; ++i) {
    if (a[i] & 1) dp++;
    else dp--;
    if (dp == 0) {
      if (i != n) {
        f.push_back(abs(a[i + 1] - a[i]));
      }
    }
  }
  int ans = 0;
  sort(f.begin(), f.end());
  for (int i = 0; i < int(f.size()); ++i) {
    if (f[i] <= b) {
      b -= f[i];
      ans++;
    }
  }
  cout << ans;
  return 0;
}
