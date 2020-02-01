#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt_neg[2] = {0}, cur_neg = 0;
  ll ans = 0LL;
  cin >> n;
  cnt_neg[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (a < 0)
      cur_neg ^= 1;
    ans += cnt_neg[cur_neg ^ 1];
    cnt_neg[cur_neg]++;
  }
  cout << ans << ' ' << 1LL * n * (n + 1) / 2 - ans;
  return 0;
}
