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

void solve() {
  int n;
  vector<int> g[4];
  set<string> s01, s10;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int mask = (((s[i][0] - '0') << 1) | (s[i].back() - '0'));
    g[mask].push_back(i);
    if (mask == 1)
      s01.insert(s[i]);
    else if (mask == 2)
      s10.insert(s[i]);
  }
  if (int(g[1].size() + g[2].size()) == 0 && int(g[0].size()) > 0 && int(g[3].size()) > 0) {
    cout << -1 << '\n';
  }
  else {
    vector<int> res;
    if (int(s10.size()) > int(s01.size()) + 1) {
      for (int i = 0; i < n; ++i) {
        int mask = (((s[i][0] - '0') << 1) | (s[i].back() - '0'));
        if (mask == 2) {
          string tmp = s[i];
          reverse(tmp.begin(), tmp.end());
          if (s01.find(tmp) == s01.end()) {
            res.push_back(i + 1);
          }
        }
      }
    }
    else if (int(s01.size()) > int(s10.size()) + 1) {
      for (int i = 0; i < n; ++i) {
        int mask = (((s[i][0] - '0') << 1) | (s[i].back() - '0'));
        if (mask == 1) {
          string tmp = s[i];
          reverse(tmp.begin(), tmp.end());
          if (s10.find(tmp) == s10.end()) {
            res.push_back(i + 1);
          }
        }
      }
    }
    int ans = int(max(s10.size(), s01.size()) - min(s10.size(), s01.size())) / 2;
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i)
      cout << res[i] << ' ';
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;)
    solve();
  return 0;
}
