#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s[2] = {0};
  cin >> n;
  for (int k = 0; k < 2; ++k)
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      s[k] += a;
    }
  if (s[0] >= s[1]) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
