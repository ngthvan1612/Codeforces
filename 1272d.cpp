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

const int N = 2e5 + 5;
int a[N], n, l[N], r[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[0] = -oo, a[n + 1] = +oo;
  l[0] = r[n + 1] = 0;
  int ans = 0;
  for (int i = 1, j = n; i <= n; ++i, --j) {
    if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
    else l[i] = 1;
    if (a[j] < a[j + 1]) r[j] = r[j + 1] + 1;
    else r[j] = 1;
    ans = max(ans, l[i]);
    ans = max(ans, r[j]);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] < a[i + 1])
      ans = max(ans, l[i - 1] + r[i + 1]);
  }
  cout << ans;
  return 0;
}
