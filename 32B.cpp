#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = int(s.length());
  s += "*";
  for (int i = 0; i < n; ++i)
    if (s[i] == '-') {
      if (s[i + 1] == '.') cout << 1;
      else cout << 2;
      i++;
    }
    else cout << 0;
  return 0;
}
