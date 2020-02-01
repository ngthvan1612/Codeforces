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
  map<int, bool> vs;
  int n, m;
  queue<ii> q;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    vs[a] = true;
    q.push(ii(a, +1));
    q.push(ii(a, -1));
  }
  ll ans = 0;
  vector<int> p;
  while (m) {
    ii u = q.front();
    q.pop();
    if (vs.find(u.first + u.second) != vs.end())
      continue;
    m--;
    ans += abs(u.second);
    p.push_back(u.first + u.second);
    vs[u.first + u.second] = true;
    for (int j = -1; j <= +1; ++j)
      if (j && vs.find(u.first + u.second + j) == vs.end()) {
        q.push(ii(u.first, u.second + j));
      }
  }
  cout << ans << '\n';
  for (int v : p)
    cout << v << ' ';
  return 0;
}
