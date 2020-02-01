#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

char a[4][4];
int dp[4][4][4];
const int hor[] = { -1, -1, -1, +0 };
const int ver[] = { +0, -1, +1, -1 };

int get(int u, int v, int w) {
  if (u < 0 || v < 0 || u > 3 || v > 3)
    return 0;
  return dp[u][v][w];
}

bool check() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == 'x') {
        for (int k = 0; k < 4; ++k) {
          dp[i][j][k] = 1 + get(i + hor[k], j + ver[k], k);
          if (dp[i][j][k] >= 3)
            return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt[2] = {0};
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
    for (int j = 0; j < 4; ++j)
      if (a[i][j] == 'o') cnt[0]++;
      else if (a[i][j] == 'x') cnt[1]++;
  }
  assert(cnt[0] == cnt[1]);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (a[i][j] == '.') {
        a[i][j] = 'x';
        if (check()) {
          cout << "YES\n";
          return 0;
        }
        a[i][j] = '.';
      }
  cout << "NO\n";
  return 0;
}
