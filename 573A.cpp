#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int a[N], n;

int calc(int x) {
  while (x % 2 == 0)
    x /= 2;
  while (x % 3 == 0)
    x /= 3;
  return x == 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g = __gcd(g, a[i]);
  }
  bool ans = true;
  for (int i = 1; i <= n; ++i) {
    if (calc(a[i] / g) != 1) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes": "No");
  return 0;
}
