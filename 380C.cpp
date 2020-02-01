#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
char a[N];
int n, m;
struct node {
  int l, r, t;
  node(int _l = 0, int _r = 0, int _t = 0) {
    l = _l; r = _r; t = _t;
  }
};
node st[4 * N];
node operator+(const node& a, const node& b) {
  node c = node();
  c.t = a.t + b.t;
  int wmin = min(a.l, b.r);
  c.t += wmin * 2;
  c.l = a.l - wmin + b.l;
  c.r = a.r + b.r - wmin;
  return c;
}

void build(int id, int l, int r) {
  if (l == r) {
    if (a[l] == '(')
      st[id] = node(1, 0, 0);
    else
      st[id] = node(0, 1, 0);
  }
  else {
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
  }
}

node get(int id, int l, int r, int u, int v) {
  if (r < u || v < l)
    return node();
  if (u <= l && r <= v)
    return st[id];
  int mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
  scanf("%s", a + 1);
  scanf("%d", &m);
  n = int(strlen(a + 1));
  build(1, 1, n);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", get(1, 1, n, l, r).t);
  }
  return 0;
}
