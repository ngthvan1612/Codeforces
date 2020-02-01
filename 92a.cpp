#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i = 1;
  cin >> n >> m;
  while (m) {
    if (i > m) {
      break;
    }
    else {
      m -= i;
    }
    i = i + 1;
    if (i > n)
      i = 1;
  }
  cout << m;
  return 0;
}
