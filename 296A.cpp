#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int c[N], n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(c, 0, sizeof c);
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    c[t]++;
  }
  c[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int w = 0;
    for (int j = 1; j <= 1000; ++j)
      if (c[w] <= c[j] && j != a[i - 1] && c[j] != 0)
        w = j;
    if (w == 0) {
      cout << "NO\n";
      return 0;
    }
    c[w]--;
    a[i] = w;
  }
  
  for (int i = 1; i <= n - 1; ++i)
    if (a[i] == a[i + 1]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}

