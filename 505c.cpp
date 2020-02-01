#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 3e4 + 5;
int cnt[N], f[N][500], n, d;

int get(int i, int j) {
  assert((0 <= j + 250 - d) && (j + 250 - d) < 500);
  return f[i][j + 250 - d];
}

int update(int i, int j, int val) {
  assert((0 <= j + 250 - d) && (j + 250 - d) < 500);
  return f[i][j + 250 - d] = val;
}

int solve(int i, int len) {
  if (get(i, len) >= 0)
    return get(i, len);
  int res = 0;
  for (int j = -1; j <= +1; ++j) {
    int new_len = len + j;
    if (i + new_len < N && i + new_len > 0 && new_len != 0) {
      res = max(res, solve(i + new_len, new_len));      
    }
  }
  return update(i, len, res + cnt[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(cnt, 0, sizeof cnt);
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  memset(f, -1, sizeof f);
  cout << solve(d, d);
  return 0;
}
