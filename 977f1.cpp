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
int n, a[N], f[N], ma[2 * N], trace[N];
ii tmp[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp[i].first);
    tmp[i].second = i;
  }
  sort(tmp + 1, tmp + 1 + n);
  for (int i = 1, prev = -16122002, cur = -1; i <= n; ++i) {
    if (prev != tmp[i].first) {
      if (tmp[i].first == prev + 1) cur++;
      else cur += 2;
      prev = tmp[i].first;
    }
    a[tmp[i].second] = cur;
  }
  memset(f, 0, sizeof f);
  memset(ma, 0, sizeof ma);
  int p = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[ma[a[i] - 1]] + 1;
    trace[i] = ma[a[i] - 1];
    if (f[ma[a[i]]] < f[i])
      ma[a[i]] = i;
    if (f[p] < f[i]) {
      p = i;
    }
  }
  printf("%d\n", f[p]);
  vector<int> res;
  while (p) {
    res.push_back(p);
    p = trace[p];
  }
  reverse(res.begin(), res.end());
  for (int v : res)
    printf("%d ", v);
  return 0;
}
