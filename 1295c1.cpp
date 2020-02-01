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
char s[N], t[N];
int n, m, nxt[N][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    cin >> s + 1 >> t + 1;
    n = int(strlen(s + 1));
    m = int(strlen(t + 1));
    for (int c = 0; c < 26; ++c)
      nxt[n][c] = -1;
    for (int i = n - 1; i >= 0; --i) {
      for (char c = 0; c < 26; ++c) {
        nxt[i][c] = nxt[i + 1][c];
      }
      nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    int ans = 1;
    for (int i = 1, pos = 0; i <= m; ++i) {
      if (nxt[pos][t[i] - 'a'] != -1) {
        pos = nxt[pos][t[i] - 'a'];
      }
      else {
        if (nxt[0][t[i] - 'a'] != -1) {
          pos = nxt[0][t[i] - 'a'];
        }
        else {
          ans = -1;
          break;
        }
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
