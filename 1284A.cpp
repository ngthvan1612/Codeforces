#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

char s[20][11], t[20][11];
int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  for (int i = 0; i < m; ++i)
    cin >> t[i];
  int q;
  for (cin >> q; q--;) {
    int y;
    cin >> y;
    y--;
    printf("%s%s\n", s[y % n], t[y % m]);
  }
  return 0;
}
