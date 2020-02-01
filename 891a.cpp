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

int n, a[2001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int g = 0, c1 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 1) c1++;
    g = __gcd(a[i], g);
  }
  if (g != 1) {
    cout << "-1";
    return 0;
  }
  if (c1) {
    cout << n - c1;
    return 0;
  }
  int mz = oo;
  for (int i = 1; i <= n - 1; ++i)
    for (int j = i + 1; j <= n; ++j) {
      printf("g: %d %d = %d\n", a[i], a[j], __gcd(a[i], a[j]));
      if (__gcd(a[i], a[j]) == 1)
        mz = min(mz, j - i);
    }
  cout << n - 1 + mz;
  return 0;
}
