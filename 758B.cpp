#include <bits/stdc++.h>

using namespace std;

string s;
int n, cnt[4] = {0};
int rev[256];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = int(s.length());
  char c[4] = {0};
  int cnt[4] = {0};
  for (int i = 0; i < n; ++i)
    if (s[i] != '!') {
      c[i % 4] = s[i];
      rev[s[i]] = i % 4;
    }
    else cnt[i % 4]++;
  const char* w = "RBYG";
  for (int i = 0; i < 4; ++i)
    cout << cnt[rev[w[i]]] << ' ';
  return 0;
}
