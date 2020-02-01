#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s[2], t[2];
  scanf("%d:%d\n%d:%d", &s[0], &s[1], &t[0], &t[1]);
  int ls = s[0] * 60 + s[1], lt = t[0] * 60 + t[1];
  int ans = ls - lt;
  if (ans < 0)
    ans += 24 * 60;
  printf("%02d:%02d", ans / 60, ans % 60);
  return 0;
}
