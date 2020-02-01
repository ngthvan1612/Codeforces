#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  string s;
  for (cin >> t; t--;) {
    cin >> s;
    int n = int(s.length());
    s += "********";
    vector<int> res;
    for (int i = 0; i < n - 2; ++i) {
      if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') res.push_back(i + 1);
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
        if (s[i + 3] == 'n' && s[i + 4] == 'e') res.push_back(i + 2), i += 2;
        else res.push_back(i + 1);
      }
    }
    cout << res.size() << '\n';
    for (int v : res)
      cout << v + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
