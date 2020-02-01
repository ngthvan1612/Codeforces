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
struct food {
  int id, c, a;
  food(int _id = 0, int _c = 0, int _a = 0) { id = _id; c = _c; a = _a; }
};
bool operator<(const food& l, const food& r) {
  return l.c < r.c || (l.c == r.c && l.id < r.id);
}
food f[N];
int n, m, rev[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> f[i].a;
    f[i].id = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> f[i].c;
  }
  sort(f + 1, f + 1 + n);
  for (int i = 1; i <= n; ++i) {
    rev[f[i].id] = i;
    //cout << "f[" << i << "].id = " << f[i].id << '\n';
  }
  int mi = 1;
  for (int i = 1; i <= m; ++i) {
    int t, d;
    cin >> t >> d;
    ll cur = 0LL;
    int dv = min(f[rev[t]].a, d);
    f[rev[t]].a -= dv;
    d -= dv;
    cur += 1LL * dv * f[rev[t]].c;
    //cout << "add " << dv << " from " << t << '\n';
    while (d && mi <= n) {
      int cmin = min(d, f[mi].a);
      d -= cmin;
      f[mi].a -= cmin;
      cur += 1LL * cmin * f[mi].c;
      //cout << "add " << cmin << " from " << f[mi].id << '\n';
      if (f[mi].a == 0) mi++;
    }
    if (d == 0) cout << cur << '\n';
    else cout << 0 << '\n';
   // cout << '\n';
  }
  return 0;
}
