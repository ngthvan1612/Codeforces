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
struct query {
  int x, type, id;
  query(int _x = 0, int _type = 0, int _id = 0) {
    x = _x;
    type = _type;
    id = _id;
  }
};
bool operator<(const query& l, const query& r) {
  return l.x < r.x || (l.x == r.x && l.id < r.id);
}
int n;

void solve() {
  cin >> n;
  vector<query> q;
  vector<ii> p;
  vector<int> f(n, 0);
  map<int, int> cnt_left;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    q.push_back(query(x, -1, i));
    q.push_back(query(y, +1, i));
    p.push_back(ii(x, y));
  }
  sort(q.begin(), q.end());
  sort(p.begin(), p.end());
  int cur = 0, mz = 0;
  for (int i = 0, r = -oo, l = -oo; i < n; ++i) {
    if (r < p[i].first) {
      cnt_left[p[i].first] = 0;
      cur++;
    }
    r = max(r, p[i].second);
  }
  debug(cur);
  set<int> st;
  for (int i = 0; i < 2 * n;) {
    int j = i;
    vector<int> open, close;
    while (j < 2 * n && q[i].x == q[j].x) {
      if (q[j].type == -1) {
        open.push_back(q[j].id);
      }
      else {
        close.push_back(q[j].id);
      }
      ++j;
    }
    if (int(st.size()) == 1 && !open.empty()) {
      f[*st.begin()]++;
    }
    for (int v : open) {
      st.insert(v);
      //printf("INS: %d\n", v);
    }
    for (int v : close) {
      st.erase(v);
      //printf("ERA: %d\n", v);
    }
    i = j;
  }
  for (int i = 0; i < 2 * n; ++i)
    if (cnt_left.find(q[i].x) != cnt_left.end() && q[i].type == -1)
      cnt_left[q[i].x]++;
  for (int i = 0; i < 2 * n; ++i)
    if (cnt_left[q[i].x] == 1 && q[i].type == -1) {
      f[q[i].id]--;
    }
  mz = -oo;
  for (int i = 0; i < n; ++i)
    mz = max(mz, f[i]);
  cout << cur + mz << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;)
    solve();
  return 0;
}
