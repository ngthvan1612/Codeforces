#include <bits/stdc++.h>

using namespace std;

int main() {
  int x = 3;
  ios::sync_with_stdio(0);    
  cin.tie(0);
  string s;
  cin >> s;
  int sum2 = 0, sum4 = 0, sum = 0, p[5];
  for (char c : s) {
    sum2 = (sum2 * 10 + c - '0') % 2;
    sum4 = (sum4 * 10 + c - '0') % 4;
    sum += c - '0';
  }
  if (sum == 0) { cout << 4; return 0; }
  for (int i = 1; i <= 4; ++i)
    p[i] = 1;
  sum2 = (sum2 - 1 + 2) % 2;
  sum4 = (sum4 - 1 + 4) % 4;
  for (int i = 0; i <= sum4; ++i)
    p[2] = p[2] * 2 % 5;
  for (int i = 0; i <= sum4; ++i)
    p[3] = p[3] * 3 % 5;
  for (int i = 0; i <= sum2; ++i)
    p[4] = p[4] * 4 % 5;
  int ans = 0;
  for (int i = 1; i <= 4; ++i) {
    ans = (ans + p[i]) % 5;
  }
  cout << ans;
  return 0;
}
