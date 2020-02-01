#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k;  

int main() {
  ios::sync_with_stdio(0);
  string a;
  cin >> n >> k >> a;
  string b(n, '0');
  for (int i = 0; i < k; ++i)
    for (int j = i; j < n; j += k)
      b[j] = a[i];
  if (b >= a) cout << n << '\n' << b;
  else {
    int jm = 0, tmp;
    for (int i = k - 1; i >= 0; --i)
      if (b[i] != '9') {
        jm = i;
        break;
      }
    b[jm]++;
    for (int i = jm; i < n; i += k)
      b[i] = b[jm];
    for (int i = jm + 1; i < k; ++i) {
      b[i] = '0';
      for (int j = i; j < n; j += k)
        b[j] = b[i];
    }
    cout << n << '\n' << b;
  }
  return 0;
}
