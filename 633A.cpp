#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x = -1, y = -1;
  cin >> a >> b >> c;
  for (y = 0; y <= c / b; ++y)
    if ((c - b * y) % a == 0) {
      x = (c - b * y) / a;
    }
  if (x >= 0) cout << "Yes";
  else cout << "No";
  return 0;
}
