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

const int N = 3e5 + 5;
int n, m, a[N], r[N], l, c[2 * N];
int id[N], dp[2 * N], mi[N], ma[N];
bool first[N];

bool cmp(int i, int j) { return r[i] < r[j]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  memset(c, 0, sizeof c);
  for (int i = 1; i <= n; ++i) {
    r[i] = i + N;
    c[i + N] = i;
    id[i] = i;
    mi[i] = ma[i] = i;
  }
  l = 1 + N;
  memset(dp, 0, sizeof dp);
  while (m--) {
    int x;
    cin >> x;
    mi[x] = 1;
    dp[l]++;
    dp[r[x]]--;
    r[x] = --l;
    c[l] = x;
  }
  for (int i = 1; i < 2 * N; ++i)
    dp[i] += dp[i - 1];
  for (int i = 1; i <= n; ++i)
    first[i] = true;
  for (int i = 2 * N - 1; i >= 0; --i) {
    int id = c[i];
    if (id == 0) continue;
    if (first[id])
      ma[id] = max(ma[id], id + dp[i]);
    else
      ma[id] = max(ma[id], 1 + dp[i]);
    first[id] = false;
  }
  for (int i = 1; i <= n; ++i)
    cout << mi[i] << ' ' << ma[i] << '\n';
  return 0;
}
