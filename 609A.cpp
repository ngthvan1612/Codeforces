#include <bits/stdc++.h>

using namespace std;

const int N = 103;
const int M = 1e5 + 3;
int f[N][M];
int n, m, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  int ans = 0;
  while (m > 0) {
    m -= a[n--];
    ans++;
  }
  cout << ans;
  return 0;
}
