#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll f[90], n;
  cin >> n;
  f[0] = 1;
  f[1] = 2;
  for (int i = 2; i <= 89; ++i)
    f[i] = f[i - 1] + f[i - 2];
  for (int i = 89; i >= 0; --i)
    if (n >= f[i]) {
      cout << i;
      return 0;
    }     
  return 0;
}
