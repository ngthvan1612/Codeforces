#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

const int N = 5e5 + 5;
int st[4 * N], d[N], sum[4 * N];
int w[2 * N], n, L[N], R[N];

int Find(int u) {
  if (d[u] == u)
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

void build(int id, int l, int r) {
  if (l == r) {
    if (w[l] < 0) {
      st[id] = -w[l];
      sum[id] = 1;
    }
    else {
      st[id] = 0;
      sum[id] = 0;
    }
  }
  else {
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    if (L[st[id * 2]] < L[st[id * 2 + 1]])
      st[id] = st[id * 2];
    else
      st[id] = st[id * 2 + 1];
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
  }
}

int get(int id, int l, int r, int u, int v) {  
  if (r < u || v < l)
    return 0;
  if (u <= l && r <= v)
    return st[id];
  int mid = (l + r) / 2;
  int e = get(id * 2, l, mid, u, v);
  int f = get(id * 2 + 1, mid + 1, r, u, v);
  if (L[e] > L[f])
    return f;
  return e;
}

int get_sum(int id, int l, int r, int u, int v) {
  if (r < u || v < l) return 0;
  if (u <= l && r <= v) return sum[id];
  int mid = (l + r) / 2;
  return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
}

typedef pair<int, int> ii;
ii a[N];
int bit[N];

void updateb(int p, int val) {
  for (int i = p; i < 2 * N; i += i & -i)
    bit[i] += val;
}

int sumb(int p) {
  int sum = 0;
  for (int i = p; i; i -= i & -i)
    sum += bit[i];
  return sum;
}

#define fi first
#define se second

bool cmp(int u, int v) {
  return a[u].se < a[v].se;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].fi >> a[i].se;
  }
  memset(bit, 0, sizeof bit);
  sort(a + 1, a + 1 + n);
  using Cmp = std::integral_constant<decltype(&cmp), &cmp>;
  set<int, Cmp> st;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    d[i] = i;
  bool ans = true;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty() && a[*st.begin()].se < a[i].fi) {
      st.erase(st.begin());
    }
    for (int v : st)
      if (a[v].se < a[i].se) {
        if (!Union(i, v)) {
          ans = false;
          break;
        }
      }
      else break;
    if (!ans) break;
    st.insert(i);
  }
  int lt = 0;
  for (int i = 1; i <= n; ++i) {
    Find(i);
    if (i == d[i])
      lt++;
  }
  if (ans && lt == 1) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
