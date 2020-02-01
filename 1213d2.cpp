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
int n, k, cnt[N];
vector<ii> g[N];

bool cmp(ii a, ii b) { return a.second < b.second; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int ans = oo;
  for (int i = N - 1; i >= 0; --i) {
    if (cnt[i]) {
      int tmp = i, r = 0;
      while (tmp) {
        g[tmp].push_back(ii(cnt[i], r));
        tmp /= 2;
        r++;
      }
      g[0].push_back(ii(cnt[i], r));
    }
  }
  for (int i = 0; i < N; ++i)
    if (int(g[i].size()) != 0) {
      int tmp = 0, sz = 0;
      sort(g[i].begin(), g[i].end(), cmp);
      for (ii v : g[i]) {
        int cmin = min(k - sz, v.first);
        sz += cmin;
        tmp += cmin * v.second;
      }
      if (sz == k) {
        ans = min(ans, tmp);
      }
    }
  if (ans == oo) cout << n;
  else cout << ans;
  return 0;
}
