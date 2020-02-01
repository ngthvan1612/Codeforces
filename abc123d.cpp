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

const int N = 1e3 + 5;
ll a[N], b[N], c[N];
int x, y, z, k;

struct elm {
  int u, v, w;
  elm(int _u = 0, int _v = 0, int _w = 0) {
    u = _u;
    v = _v;
    w = _w;
  }
  ll get() const {
    return a[u] + b[v] + c[w];
  }
};

bool operator<(const elm& p, const elm& q) {
  return p.get() < q.get();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> z >> k;
  for (int i = 1; i <= x; ++i) cin >> a[i];
  for (int i = 1; i <= y; ++i) cin >> b[i];
  for (int i = 1; i <= z; ++i) cin >> c[i];
  sort(a + 1, a + 1 + x);
  sort(b + 1, b + 1 + y);
  sort(c + 1, c + 1 + z);
  priority_queue<elm, vector<elm>, less<elm> > heap;
  for (int i = 1; i <= x; ++i)
    for (int j = 1; j <= y; ++j)
      heap.push(elm(i, j, z));
  while (k--) {
    elm t = heap.top();
    heap.pop();
    cout << t.get() << '\n';
    t.w--;
    if (t.w >= 1)
      heap.push(t);
  }
  return 0;
}
