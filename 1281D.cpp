#include <bits/stdc++.h>

using namespace std;

const int N = 65;
char a[N][N];
bool row[N], col[N];
int r, c, t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
      cin >> a[i] + 1;
    int cnt[2] = {0};
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        if (a[i][j] == 'A') cnt[0]++;
        else cnt[1]++;
    if (cnt[1] == 0) cout << 0 << '\n';
    else if (cnt[0] == 0) cout << "MORTAL\n";
    else {
      for (int i = 1; i <= max(r, c); ++i)
        row[i] = col[i] = true;
      for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
          if (a[i][j] == 'P')
            row[i] = col[j] = false;
      if (r == 1) {
        if (col[1] || col[c]) cout << 1;
        else cout << 2;
      }
      else if (c == 1) {
        if (row[1] || row[r]) cout << 1;
        else cout << 2;
      }
      else {
        bool okr = false, okc = false;
        for (int i = 1; i <= r; ++i)
          okr |= row[i];
        for (int j = 1; j <= c; ++j)
          okc |= col[j];
        if (row[1] || row[r] || col[1] || col[c]) cout << 1;
        else if (okr || okc) cout << 2;
        else {
          if (a[1][1] == 'A' || a[1][c] == 'A' || a[r][1] == 'A' || a[r][c] == 'A') cout << 2;
          else {
            bool okt = false;
            for (int i = 1; i <= r; ++i)
              for (int j = 1; j <= c; ++j)
                if (i == 1 || j == 1 || i == r || j == c) {
                  if (a[i][j] == 'A')
                    okt = true;
                }
            if (okt) cout << 3;
            else cout << 4;
          }
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
