#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int n, a[101], p[101], cnt, c[2];
int f[101][101][101][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cnt = 0;
  c[0] = c[1] = 0;
  p[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = p[i - 1];
    if (a[i] != 0) {
      c[a[i] % 2]++;
    }
    else p[i]++;
  }
  c[0] = n / 2 - c[0];
  c[1] = (n + 1) / 2 - c[1];
  for (int i = 0; i <= c[0]; ++i)
    for (int j = 0; j <= c[1]; ++j)
      for (int k = 0; k <= n; ++k)
        f[k][i][j][0] = f[k][i][j][1] = oo;
  f[0][0][0][0] = f[0][0][0][1] = 0;
  //printf("c[] = {%d, %d}\n", c[0], c[1]);
  a[0] = a[1];
  for (int k = 1; k <= n; ++k) {
    for (int i = 0; i <= min(p[k], c[0]); ++i) {
      if (c[1] >= p[k] - i) {
        int j = p[k] - i;
        //printf("DEBUG: {k, p, i, j} = {%d, %d, %d, %d}\n", k, p[k], i, j);
        if (k == 1) {
          if (a[k] != 0) {
            f[k][i][j][a[k] % 2] = 0;
          }
          else {
            f[k][i][j][0] = f[k][i][j][1] = 0;
          }
        }
        else {
          if (a[k] != 0) {
            if (a[k - 1] != 0) {
              f[k][i][j][a[k] % 2] = f[k - 1][i][j][a[k - 1] % 2] + (a[k] + a[k - 1]) % 2;
            }
            else {
              if (i > 0)
                f[k][i][j][a[k] % 2] = min(f[k][i][j][a[k] % 2], f[k - 1][i][j][0] + a[k] % 2);
              if (j > 0)
                f[k][i][j][a[k] % 2] = min(f[k][i][j][a[k] % 2], f[k - 1][i][j][1] + (a[k] + 1) % 2);
            }
          }
          else {
            if (a[k - 1] != 0) {
              if (i > 0)
                f[k][i][j][0] = f[k - 1][i - 1][j][a[k - 1] % 2] + (a[k - 1] + 0) % 2;
              if (j > 0)
                f[k][i][j][1] = f[k - 1][i][j - 1][a[k - 1] % 2] + (a[k - 1] + 1) % 2;
            }
            else {
              if (i > 0) {
                f[k][i][j][0] = min(f[k][i][j][0], f[k - 1][i - 1][j][0]);
                if (j > 0)
                  f[k][i][j][0] = min(f[k][i][j][0], f[k - 1][i - 1][j][1] + 1);
              }
              if (j > 0) {
                f[k][i][j][1] = min(f[k][i][j][1], f[k - 1][i][j - 1][1]);
                if (i > 0)
                  f[k][i][j][1] = min(f[k][i][j][1], f[k - 1][i][j - 1][0] + 1);
              }
            }
          }
        }
        //printf("f[%d][%d][%d] = {%d, %d}\n", k, i, j, f[k][i][j][0], f[k][i][j][1]);
      }
    }
  }
  cerr << "DEBUG: " << f[n][c[0]][c[1]][0] << ", " << f[n][c[0]][c[1]][1] << '\n';
  cout << min(f[n][c[0]][c[1]][0], f[n][c[0]][c[1]][1]);
  return 0;
}
