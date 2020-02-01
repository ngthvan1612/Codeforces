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
int n, a[N], ans[N];
bool vs[N];
vector<int> g[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  queue<int> Q;
  memset(ans, 0, sizeof ans);
  for (int i = 1; i <= n; ++i) {
    bool ok = false;
    if (i - a[i] >= 1) {      
      g[i - a[i]].push_back(i);
      if ((a[i] + a[i - a[i]]) % 2) {
        vs[i] = ans[i] = 1;
        ok = true;
      }
    }
    if (i + a[i] <= n) {
      g[i + a[i]].push_back(i);
      if ((a[i] + a[i  + a[i]]) % 2) {
        vs[i] = ans[i] = 1;
        ok = true;
      }
    }
    if (ok) Q.push(i);
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v : g[u]) {
      if (!vs[v]) {
        ans[v] = ans[u] + 1;
        Q.push(v);
        vs[v] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!vs[i]) cout << -1 << ' ';
    else cout << ans[i] << ' ';
  return 0;
}
