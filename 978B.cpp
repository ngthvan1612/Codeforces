#include <bits/stdc++.h>

using namespace std;

int n;
char a[103];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a + 1;
  int ans = 0;
  for (int i = 1; i <= n;) {
    if (a[i] != 'x') ++i;
    else {
      int j = i;
      while (j <= n && a[j] == 'x')
        ++j;
      ans += max(0, j - i - 2);
      i = j;
    }
  }
  cout << ans;
  return 0;
}
