#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], ans[N], l[N], r[N];
int d[N], top = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  stack<int> st;
  d[0] = 0;
  top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top > 0 && a[d[top]] >= a[i])
      --top;
    l[i] = d[top] + 1;
    d[++top] = i;
  }
  d[0] = n + 1;
  top = 0;
  for (int i = n; i >= 1; --i) {
    while (top > 0 && a[d[top]] >= a[i])
      --top;
    r[i] = d[top] - 1;
    d[++top] = i;
  }
  memset(ans, 0, sizeof ans);
  for (int i = 1; i <= n; ++i) {
    int len = r[i] - l[i] + 1;
    ans[len] = max(ans[len], a[i]);
  }
  for (int i = n - 1; i >= 1; --i)
    ans[i] = max(ans[i], ans[i + 1]);
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';
  return 0;
}
