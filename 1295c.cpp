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

const int N = 1e5 + 5;
int n, m, w[N][26];
char s[N], t[N];

int solve() {
  cin >> s + 1 >> t + 1;
  n = int(strlen(s + 1));
  m = int(strlen(t + 1));
  for (int i = 0; i <= n + 2; ++i)
    for (int j = 0; j < 26; ++j)
      w[i][j] = -1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      if (s[i + 1] - 'a' == j)
        w[i][j] = i + 1;
      else
        w[i][j] = w[i + 1][j];
    }
  }
  int pos = 1, ans = 0;
  while (pos <= m) {
    int i = pos, j = 0;
    bool ok = false;
    while (i <= m && w[j][t[i] - 'a'] > 0) {
      j = w[j][t[i] - 'a'];
      i++;
      ok = true;
    }
    if (!ok) {
      ans = -1;
      break;
    }
    ans++;
    pos = i;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;)
    cout << solve() << '\n';
  return 0;
}
