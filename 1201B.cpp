#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  typedef long long ll;
  ll sum = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  if (sum % 2 == 0 && a[n] <= sum - a[n])
    cout << "YES";
  else cout << "NO";
  return 0;
}
