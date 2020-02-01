#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
typedef long long ll;
int n, m;
ll k;

int main() {
  cin >> n >> m >> k;
  ll L = 1, R = 1LL * m * n, res = -1;
  while (L <= R) {
    ll mid = (L + R) / 2;
    ll sz = 0;
    for (int i = 1; i <= m; ++i)
      sz += min(1LL * n, mid / i);
    if (sz >= k) {
      res = mid;
      R = mid - 1;
    }
    else L = mid + 1;
  }
  cout << res;
  return 0;
}
