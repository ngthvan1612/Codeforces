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
int a[N], n, m;

struct people {
  ll d;
  int i;
  people(ll _d = 0, int _i = 0) { d = _d; i = _i; }
};
bool operator>(const people& l, const people& r) { return abs(l.d) > abs(r.d); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  map<ll, bool> vs;
  priority_queue<people, vector<people>, greater<people> > heap;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    vs[1LL * a[i]] = true;
    heap.push(people(+1LL, i));
    heap.push(people(-1LL, i));
  }
  vector<ll> f;
  ll res = 0;
  while (m) {
    people t = heap.top();
    heap.pop();
    ll x = t.d + a[t.i];
    if (vs.find(x) != vs.end()) continue;
    m--;
    vs[x] = true;
    f.push_back(x);
    res += abs(t.d);
    heap.push(people(t.d + 1LL, t.i));
    heap.push(people(t.d - 1LL, t.i));
  }
  cout << res << '\n';
  for (ll v : f)
    cout << v << ' ';
  return 0;
}
