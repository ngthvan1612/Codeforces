#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  for (cin >> T; T--;) {
    int a, b;
    cin >> a >> b;
    if (a > b)  
      swap(a, b);
    int ans = (b - a) / 5;
    b -= ans * 5;
    while (b >= a + 2) {
      b -= 2;
      ans++;
    }
    if (a != b) {
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
