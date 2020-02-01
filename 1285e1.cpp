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

struct query {
  int x, type, id;
  query(int _x = 0, int _type = 0, int _id = 0) {
    x = _x;
    type = _type;
    id = _id;
  }
};
bool operator<(const query& l, const query& r) {
  return (l.x < r.x) || (l.x == r.x && l.type > r.type);
}

int solve() {
  int n, ans = 0;
  cin >> n;
  vector<ii> seg(n);
  for (ii &p : seg)
    cin >> p.first >> p.second;
  sort(seg.begin(), seg.end());
  vector<query> q;
  for (int i = 0; i < n; ++i) {
    q.push_back(query(seg[i].first, +1, i));
    q.push_back(query(seg[i].second, -1, i));
  }
  sort(q.begin(), q.end());
  set<int> st;
  vector<int> f(n, 0);
  map<int, int> cnt;
  for (int i = 0, r = -oo, w = -oo; i < 2 * n; ++i) {
    if (q[i].type == 1) {
      if (cnt.find(q[i].x) != cnt.end())
        cnt[q[i].x]++;
      if (r < q[i].x) {
        ans++;
        cnt[q[i].x]++;
      }
      if (w != q[i].x) {
        if (int(st.size()) == 1) {
          f[*st.begin()]++;
        }
      }
      r = max(r, seg[q[i].id].second);
      w = q[i].x;
      st.insert(q[i].id);
    }
    else {
      st.erase(q[i].id);
    }
  }
  int mz = -oo;
  for (int i = 0; i < n; ++i) {
    if (cnt[seg[i].first] == 1) {
      f[i]--;
    }
    mz = max(mz, f[i]);
  }
  debug(ans, mz);
  return mz + ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;)
    cout << solve() << '\n';
  return 0;
}
