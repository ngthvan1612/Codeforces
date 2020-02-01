#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

struct ds {
  int* w, n;
  ll * t;
  ds() { w = NULL; t = NULL; }
  ds(int* a, int sz) {
    int* p = new int[sz];
    memcpy(p, a + 1, sz * sizeof(int));
    sort(p, p + sz);
    n = unique(p, p + sz) - p;
    w = new int[n];
    memcpy(w, p, n * sizeof(int));
    t = new ll[n];
    for (int i = 0; i < n; ++i)
      t[i] = 0LL;
    delete[] p;
  }
  int Find(int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (w[mid] > key) r = mid - 1;
      else if (w[mid] < key) l = mid + 1;
      else {
        return mid;
      }
    }
    return -1;
  }
  void update(int key, ll val) {
    int pos = Find(key);
    if (pos >= 0) {
      t[pos] += val;
    }
  }
  ll get(int key) {
    int pos = Find(key);
    if (pos >= 0)
      return t[pos];
    return 0LL;
  }
};

int a[N], n, k;
ds f[2];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  f[0] = ds(a, n);
  f[1] = ds(a, n);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] % k == 0) {
      if (i >= 3)
        ans += f[1].get(a[i] / k);
      if (i >= 2)
        f[1].update(a[i], f[0].get(a[i] / k));
    }
    f[0].update(a[i], 1LL);
  }
  cout << ans;
  return 0;
}
