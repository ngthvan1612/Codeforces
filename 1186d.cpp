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
  int n;
  cin >> n;
  vector<double> a(n);
  vector<int> c, f;
  vector<bool> ans(n, false);
  for (double& x : a) {
    cin >> x;
    c.push_back(int(ceil(x)));
    f.push_back(int(floor(x)));
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += c[i];
  }
  for (int i = 0; i < n; ++i) {
    if (abs(sum - c[i] + f[i]) < abs(sum)) {
      sum += f[i] - c[i];
      ans[i] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i]) cout << f[i] << '\n';
    else cout << c[i] << '\n';
  }
  return 0;
}
