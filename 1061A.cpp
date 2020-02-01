#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s, ans = 0;
  cin >> n >> s;
  ans = s / n + (s % n != 0);
  cout << ans;
  return 0;
}
