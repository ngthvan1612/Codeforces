#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    string s, c, res;
    cin >> s >> c;
    int n = int(s.length());
    int m = int(c.length());
    for (int i = 0; i < n; ++i) {
      int k = i;
      for (int j = i + 1; j < n; ++j)
        if (s[j] <= s[k])
          k = j;
      if (s[i] != s[k]) {
        swap(s[k], s[i]);
        break;
      }
    }
    if (s < c) cout << s << '\n';
    else cout << "---\n";
  }
  return 0;
}
