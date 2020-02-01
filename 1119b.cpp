#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e3 + 5;
int a[N], b[N], n, h;

bool check(int w) {
  for (int i = 1; i <= w; ++i)
    b[i] = a[i];
  sort(b + 1, b + 1 + w);
  ll ans[2] = {0};
  //printf("CHECK: %d\n", w);
  //printf("Case 1:\n");
  for (int i = 1; i <= w; i += 2) {
    ans[0] += b[min(w, i + 1)];
    //printf("ADD: b[%d]\n", min(w, i + 1));
  }
  ans[1] = b[1];
  //printf("Case 2:\n");
  //printf("ADD: b[1]\n");
  for (int i = 2; i <= w; i += 2) {
    ans[1] += b[min(w, i + 1)];
    //printf("ADD: b[%d]\n", min(w, i + 1));
  }
  //printf("\n");
  return ans[0] <= h || ans[1] <= h;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> h;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int low = 1, high = n, ans = 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid)) {
      low = mid + 1;
      ans = mid;
    }
    else high = mid - 1;
  }
  cout << ans;
  return 0;
}
