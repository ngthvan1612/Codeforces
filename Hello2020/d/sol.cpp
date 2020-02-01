#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e5 + 5;
int n, s[N][2][2], d[N];

struct elm {
  int s[4];
  elm() { memset(s, 0, sizeof s); }
};
bool operator<(const elm& L, const elm& R) {
  return L.s[0] < R.s[0] || (L.s[0] == R.s[0] && L.s[1] < R.s[1]);
}
bool cmpElm1(const elm& L, const elm& R) {
  return L.s[1] < R.s[1];
}
elm a[N];
bool cmpSet(int u, int v) {
  return a[u].s[1] < a[v].s[1];
}

int Find(int u) {
  if (u == d[u])
    return u;
  return d[u] = Find(d[u]);
}

bool Union(int u, int v) {
  u = Find(u);
  v = Find(v);
  if (u == v)
    return false;
  d[u] = v;
  return true;
}

int st[4 * 4 * N], lazy[4 * 4 * N];

void update(int id, int l, int r, int u, int v, int val) {
  if (lazy[id]) {
    st[id] += (r - l + 1) * lazy[id];
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
  if (r < u || v < l) return;
  if (u <= l && r <= v) {
    st[id] += (r - l + 1) * val;
    if (l != r) {
      lazy[id * 2] += val;
      lazy[id * 2 + 1] += val;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, v, val);
  update(id * 2 + 1, mid + 1, r, u, v, val);
  st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
  if (lazy[id] != 0) {
    st[id] += (r - l + 1) * lazy[id];
    if (l != r) {
      lazy[id * 2] += lazy[id];
      lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return st[id];
  int mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

bool solve() {
  memset(st, 0, sizeof st);
  memset(lazy, 0, sizeof lazy);
  sort(a + 1, a + 1 + n);  
  using Cmp = std::integral_constant<decltype(&cmpSet), &cmpSet>;
  set<int, Cmp> mem;
  for (int i = 1; i <= n; ++i) {
    while (!mem.empty() && a[*mem.begin()].s[1] < a[i].s[0]) {
      int u = *mem.begin();
      update(1, 1, 4 * n, a[u].s[2], a[u].s[3], 1);
      mem.erase(mem.begin());
    }
    if (get(1, 1, 4 * n, a[i].s[2], a[i].s[3]) > 0) {
      return false;
    }
    mem.insert(i);
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  set<int> st;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j) {
      cin >> a[i].s[j];
      st.insert(a[i].s[j]);
    }
  vector<int> tmp(st.begin(), st.end());
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j)
      a[i].s[j] = lower_bound(tmp.begin(), tmp.end(), a[i].s[j]) - tmp.begin() + 1;
  bool ans = 1;
  ans &= solve();
  for (int i = 1; i <= n; ++i) {
    swap(a[i].s[0], a[i].s[2]);
    swap(a[i].s[1], a[i].s[3]);
  }
  ans &= solve();
  if (ans) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
