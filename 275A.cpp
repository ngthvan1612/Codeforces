#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3][3], w[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      w[i][j] = 1;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> a[i][j];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] % 2 == 1) {
        for (int u = -1; u <= +1; ++u)
          for (int v = -1; v <= +1; ++v) {
            if (abs(u) == abs(v) && abs(u) == 1) continue;
            int newi = i + u;
            int newj = j + v;
            if (newi >= 0 && newi < 3 && newj >= 0 && newj < 3) {
              w[newi][newj] ^= 1;
            }
          }
      }
    }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      cout << w[i][j];
    cout << '\n';
  }
  return 0;
}
