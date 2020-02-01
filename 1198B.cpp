#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], q;
bool lk[N];
struct query {
  int t, p, x;
  query(int _t = 0, int _p = 0, int _x = 0) {
    t = _t;
    p = _p;
    x = _x;
  }
};
query w[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> w[i].t;
    if (w[i].t == 1)
      cin >> w[i].p >> w[i].x;
    else
      cin >> w[i].x;
  }
  int mz = 0;
  w[mz].x = 0;
  for (int i = q; i >= 1; --i) {
    if (w[i].t == 2) {
      if (w[mz].x < w[i].x) {
        mz = i;
      }
    }
  }
  for (int i = 1; i < mz; ++i)
    if (w[i].t == 1)
      a[w[i].p] = w[i].x;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < w[mz].x)
      a[i] = w[mz].x;
  }
  int maxz = 0;
  memset(lk, 0, sizeof lk);
  for (int i = q; i > mz; --i) {
    if (w[i].t == 1) {
      if (!lk[w[i].p]) {
        lk[w[i].p] = true;
        a[w[i].p] = max(maxz, w[i].x);
      }
    }
    else
      maxz = max(maxz, w[i].x);
  }
  for (int i = 1; i <= n; ++i)
    cout << a[i] << ' ';
  return 0;
}
