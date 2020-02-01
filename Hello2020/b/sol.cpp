#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e5 + 5;
int n, s[N], l;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<ii> f;
  vector<int> b;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l;
    for (int j = 1; j <= l; ++j)
      cin >> s[j];
    bool ok = true;
    for (int j = 1; j <= l - 1; ++j) {
      if (s[j] < s[j + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      f.push_back(make_pair(s[1], s[l]));
      b.push_back(s[1]);
    }
  }
  ll sum = 0;
  sort(b.begin(), b.end());
  sort(f.begin(), f.end());
  //for (int i = 0; i < int(f.size()); ++i)
  //  printf("DEBUG: [%d, %d]\n", f[i].first, f[i].second);
  for (int i = 0; i < int(f.size()); ++i) {
    int l = 0, r = int(f.size()) - 1, c = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (b[mid] <= f[i].second) {
        c = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    if (c >= 0) {
      sum += c + 1;
      //printf("SZ: [%d, %d] = %d\n", f[i].first, f[i].second, c + 1);
    }
  }
  cout << 1LL * n * n - sum << '\n';
  return 0;
}
