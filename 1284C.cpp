#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 2e5 + 5e4 + 5;
int mul(const int& a, const int& b, const int& mod) {
  return int((1LL * a * b) % (1LL * mod));
}
int sum(const int& a, const int& b, const int& mod) {
  return (a + b) % mod;
}
int n, m, f[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  f[0] = 1;
  for (int i = 1; i <= n; ++i)
    f[i] = mul(f[i - 1], i, m);
  int ans = 0;
  for (int k = 1; k <= n; ++k) {
    int tmp = 1;
    tmp = mul(tmp, n - k + 1, m);
    tmp = mul(tmp, f[k], m);
    tmp = mul(tmp, f[n - k + 1], m);
    ans = sum(ans, tmp, m);
  }
  cout << ans;
  return 0;
}
