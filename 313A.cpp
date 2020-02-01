#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, w = 1;
  cin >> n;
  if (n < 0) {
    w = -1;
    n = w * n;
    n = n / 100 * 10 + min(n % 10, n / 10 % 10);    
  }
  cout << n * w;
  return 0;
}
