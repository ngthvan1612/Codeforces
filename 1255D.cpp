#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
vector<char> w;
char a[N][N], ans[N][N];
int r, c, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ////Init
  for (char s = 'a'; s <= 'z'; ++s)
    w.push_back(s);
  for (char s = 'A'; s <= 'Z'; ++s)
    w.push_back(s);
  for (char s = '0'; s <= '9'; ++s)
    w.push_back(s);
  ///
  int T = 0;
  for (cin >> T; T--;) {
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++i)
      cin >> (a[i] + 1);
    int rice = 0;
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        rice += (a[i][j] == 'R');
    int need = rice / k;
    int md = rice % k;
    int lr = +1;
    int cur = 0, cnt = 0;
    for (int i = 1; i <= r; ++i) {
      int delta = lr;
      int start = (delta > 0 ? 1 : c);
      int end = (delta > 0 ? c : 1);
      for (int j = start; j != (end + delta); j += delta) {
        if (a[i][j] == 'R') cnt++;
        ans[i][j] = w[min(k - 1, cur)];
        if (md > 0) {
          if (cnt == need + 1) {
            md--;
            cur++;
            cnt = 0;
          }
        }
        else {
          if (cnt == need) {
            cur++;
            cnt = 0;
          }
        }
      }
      lr *= -1;
    }
    for (int i = 1; i <= r; ++i) {
      ans[i][c + 1] = '\0';
      cout << ans[i] + 1 << '\n';
    }
  }
  return 0;
}
