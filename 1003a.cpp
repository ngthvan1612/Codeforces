#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt[101] = {0};
  int ans = 0, n, a;
  for (cin >> n; n--;) {
    cin >> a;
    cnt[a]++;
    ans = max(ans, cnt[a]);
  }
  cout << ans;
  return 0;
}
