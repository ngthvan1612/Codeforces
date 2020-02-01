#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;
typedef long long ll;
ll m[N][N], a[N];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> m[i][j];
  for (int i = 2; i <= n - 1; ++i)
    a[i] = sqrt(m[i][i + 1] * m[1][i] / m[1][i + 1]);
  a[1] = m[1][2] / a[2];
  a[n] = m[n][2] / a[2];
  for (int i = 1; i <= n; ++i)
    cout << a[i] << ' ';
  return 0;
}
