///created: 9/Jun/2019 12:58:23
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
  if (a > b) { a = b; return true; }
  return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < int(s.length()) - 1; ++i)
      if ('A' <= s[i] && s[i] <= 'Z' && '0' <= s[i + 1] && s[i + 1] <= '9')
        cnt++;
    if (cnt == 2) {
      int r = 0, c = 0, j = 1;
      while (j < int(s.length()) && '0' <= s[j] && s[j] <= '9')
        r = r * 10 + s[j++] - '0';
      ++j;
      while (j < int(s.length()))
        c = c * 10 + s[j++] - '0';
      string tmp;
      while (c) {
        tmp += char('A' + (c - 1) % 26);
        c = (c - 1) / 26;
      }
      reverse(tmp.begin(), tmp.end());
      printf("%s%d\n", tmp.c_str(), r);
    }
    else {
      int r = 0, c = 0, i = 0;
      while (i < int(s.length()) && 'A' <= s[i] && s[i] <= 'Z')
        c = c * 26 + s[i++] - 'A' + 1;
      while (i < int(s.length()))
        r = r * 10 + s[i++] - '0';
      printf("R%dC%d\n", r, c);
    }
  }
  return 0;
}
