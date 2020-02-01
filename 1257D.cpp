#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 +5;
struct hero {
  int p, s;
} h[N];
bool operator<(const hero& l, const hero& r) {
  return l.s < r.s;
}
int t, n, m, a[N], st[4 * N];
void build(int id, int l, int r) {
  if (l == r) {
    st[id] = h[l].p;
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
  if (r < u || v < l)
    return -1e9 + 7;
  if (u <= l && r <= v)
    return st[id];
  int mid = (l + r) / 2;
  int r1 = get(id * 2, l, mid, u, v);
  int r2 = get(id * 2 + 1, mid + 1, r, u, v);
  return max(r1, r2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
      cin >> h[i].p >> h[i].s;
    sort(h + 1, h + 1 + m);
    build(1, 1, m);
    int ans = 0;
    for (int i = 1; i <= n;) {
      int j = i;
      int w = 0, cost = -1;
      while (j <= n) {
        w = max(w, a[j]);
        int L = 1, R = m, res = -1;
        while (L <= R) {
          int mid = (L + R) / 2;
          if (h[mid].s >= j - i + 1) {
            res = mid;
            R = mid - 1;
          }
          else L = mid + 1;
        }
        if (res == -1) break;
        int _cost = get(1, 1, m, res, m);
        if (_cost < w) break;
        cost = _cost;
        ++j;
      }
      if (cost == -1) {
        ans = -1;
        break;
      }
      int next = max(j, i + 1);
      //printf("%d %d %d\n", i, next - 1, cost);
      ans++;
      i = next;
    }
    cout << ans << '\n';
  }
  return 0;
