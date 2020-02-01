#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 2e6 + 5;
char s[N];
int n, dp[10][10][10], ans[10][10];

void calc(int a, int b) {
  queue<int> Q;
  Q.push(a);
  Q.push(b);
  dp[a][b][a] = dp[a][b][b] = 1;
  dp[b][a][a] = dp[b][a][b] = 1;
  int* v = new int[2];
  while (!Q.empty()) {
    int f = Q.front(); Q.pop();
    v[0] = (f + a) % 10;
    v[1] = (f + b) % 10;
    for (int k = 0; k < 2; ++k) {
      if (dp[a][b][v[k]] == oo) {
        dp[a][b][v[k]] = dp[a][b][f] + 1;
        dp[b][a][v[k]] = dp[b][a][f] + 1;
        Q.push(v[k]);
      }
    }
  }
  delete[] v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ///init
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      for (int k = 0; k < 10; ++k)
        dp[i][j][k] = oo;
  for (int i = 0; i < 10; ++i) {
    for (int j = i; j < 10; ++j) {
      calc(i, j);
    }
  }
  ///process
  cin >> s + 1;
  n = int(strlen(s + 1));
  for (int i = 0; i < 10; ++i)
    for (int j = i; j < 10; ++j) {
      ans[i][j] = 0;
      bool ok = true;
      for (int t = 1; t <= n - 1; ++t) {
        int w = dp[i][j][(s[t + 1] - s[t] + 10) % 10];
        if (w == oo) {
          ok = false;
          break;
        }
        ans[i][j] += w - 1;
      }
      if (!ok)
        ans[i][j] = -1;
      ans[j][i] = ans[i][j];
    }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
