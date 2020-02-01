#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
typedef long long ll;
char a[N];
int n, k, f[N];

int main() {
  scanf("%d\n%s", &k, a + 1);
  n = int(strlen(a + 1));
  f[0] = 0;
  for (int i = 1; i <= n; ++i)
    f[i] = f[i - 1] + int(a[i] - '0');
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    int l = -1, r = -1, low, high, tmp, mid;
    ///Left
    low = 1, high = i;
    while (low <= high) {
      mid = (low + high) / 2;
      tmp = f[i] - f[mid - 1];
      if (tmp > k) low = mid + 1;
      else if (tmp < k) high = mid - 1;
      else {
        l = mid;
        high = mid - 1;
      }
    }
    ///Right
    low = 1, high = i;
    while (low <= high) {
      mid = (low + high) / 2;
      tmp = f[i] - f[mid - 1];
      if (tmp > k) low = mid + 1;
      else if (tmp < k) high = mid - 1;
      else {
        r = mid;
        low = mid + 1;
      }
    }
    if (l == -1) continue;
    ans += r - l + 1;
  }
  cout << ans;
  return 0;
}
