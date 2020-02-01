#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], m, ans[N], l[N], r[N], bit[N];
typedef pair<int, int> ii;
ii rem[N];
#define fi first
#define se second
struct query {
  int k, pos, id;
  query() { }
};
bool operator<(const query& l, const query& r) {
  return l.k < r.k;
}
query q[N];

void update(int p, int val) {
  for (int i = p; i < N; i += i & -i)
    bit[i] += val;
}

int get(int p) {
  int res = 0;
  for (int i = p; i; i -= i & -i)
    res += bit[i];
  return res;
}

int bin_search(int v) {
  int pos = 0, sum = 0;
  for (int i = 18; i >= 0; --i) {
    if (pos + (1 << i) < N && sum + bit[pos + (1 << i)] < v) {
      pos += (1 << i);
      sum += bit[pos];
    }
  }
  return pos + 1;
}

void del(int pos) {
//  fprintf(stderr, "[DEBUG]: delete %d\n", pos);
  int fl = l[pos];
  int fr = r[pos];
  l[fr] = fl;
  r[fl] = fr;
  update(pos, -1);
/*  fprintf(stderr, "[%d, %d, %d] ", fl, pos, fr);
  for (int i = 1; i <= n; ++i)
    fprintf(stderr, "%d ", get(i));
  fprintf(stderr, "\n");
*/
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(r, 0, sizeof r);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    rem[i] = ii(a[i], -i);
  }
  sort(rem + 1, rem + 1 + n);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].k >> q[i].pos;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m);
  for (int i = 1; i <= n + 1; ++i)
    l[i] = i - 1;
  for (int i = 0; i <= n; ++i)
    r[i] = i + 1;
  memset(bit, 0, sizeof bit);
  for (int i = 1; i <= n; ++i)
    update(i, 1);
  int cur = n;
  for (int i = m; i >= 1; --i) {
    while (cur > q[i].k) {
      del(-rem[n - cur + 1].se);
      cur--;
    }
    ans[q[i].id] = a[bin_search(q[i].pos)];
  }
  for (int i = 1; i <= m; ++i)
    cout << ans[i] << '\n';
  return 0;
}
