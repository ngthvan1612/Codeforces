#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  for (cin >> t; t--;) {
    string s;
    cin >> s;
    char c = s[s.length() - 1];
    if (c == 'o') cout << "FILIPINO\n";
    else if (c == 'u') cout << "JAPANESE\n";
    else cout << "KOREAN\n";
  }
  return 0;
}
