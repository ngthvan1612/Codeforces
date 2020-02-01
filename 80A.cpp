#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  int n, m, e;
  cin >> n >> m;
  for (int i = n + 1; i <= 100; ++i)
    if (check(i)) {
      e = i;
      break;
    }
  if (m == e) cout << "YES";
  else cout << "NO";
  return 0;
}
