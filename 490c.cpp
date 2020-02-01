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
ll f[N], g[N], a, b, w[N];
char s[N];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s + 1 >> a >> b;
  n = int(strlen(s + 1));
  f[0] = g[n + 1] = 0;
  w[0] = 1;
  for (int i = 1; i <= n; ++i)
    w[i] = (w[i - 1] * 10) % b;
  for (int i = 1; i <= n; ++i)
    f[i] = (f[i - 1] * 10 + s[i] - '0') % a;
  for (int i = n; i >= 1; --i)
    g[i] = (g[i + 1] + (s[i] - '0') * w[n - i]) % b;
  for (int i = 1; i < n; ++i)
    if (f[i] == 0 && g[i + 1] == 0 && s[i + 1] != '0') {
      cout << "YES\n";
      for (int j = 1; j <= i; ++j)
        cout << s[j];
      cout << '\n';
      for (int j = i + 1; j <= n; ++j)
        cout << s[j];
      return 0;
    }
  cout << "NO\n";
  return 0;
}
