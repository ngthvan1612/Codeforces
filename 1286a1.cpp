#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e2 + 5;
const int ver[] = { +1, -1 };
int a[N], n;

bool cmp(ii a, ii b) {
  if (b.first == 1 || b.second == n)
    return true;
  return a.second - a.first < b.second - b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt[2] = {0}, ans = 0;
  cin >> n;
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) {
      ok = false;
      a[i] %= 2;
      cnt[a[i]]++;
    }
    else a[i] = -1;
  }
  if (ok) {
    if (n == 1)
      cout << 0;
    else cout << 1;
    return 0;
  }
  vector<ii> res;
  a[n + 1] = 1;
  for (int i = 1, cnt = 0, f = 1; i <= n + 1; ++i) {
    if (a[i] != -1) {
      if (cnt > 0) {
        res.push_back(ii(f, i - 1));
        cnt = 0;
      }
      f = i + 1;
    }
    else cnt++;
  }
  a[n + 1] = -1;
  for (int i = 1, cnt = 0, f = 1; i <= n + 1; ++i) {
    if (a[i] == -1) {
      if (cnt > 0) {
        for (int j = f; j <= i - 2; ++j)
          ans += (a[j] ^ a[j + 1]);
      }
      f = i + 1;
      cnt = 0;
    }
    else cnt++;
  }
  sort(res.begin(), res.end(), cmp);
  cnt[0] = n / 2 - cnt[0];
  cnt[1] = (n + 1) / 2 - cnt[1];
  for (ii p : res) {
    int len = p.second - p.first + 1;
    if (p.first == 1) {
      assert(a[p.second + 1] >= 0);
      if (len <= cnt[a[p.second + 1]]) {
        cnt[a[p.second + 1]] -= len;
      }
      else ans++;
    }
    else if (p.second == n) {
      assert(a[p.first - 1] >= 0);
      if (len <= cnt[a[p.first - 1]]) {
        cnt[a[p.first - 1]] -= len;
      }
      else ans++;
    }
    else {
      assert(a[p.first - 1] >= 0 && a[p.second + 1] >= 0);
      if (a[p.first - 1] == a[p.second + 1]) {
        if (len <= cnt[a[p.second + 1]]) {
          cnt[a[p.second + 1]] -= len;
        }
        else ans += 2;
      }
      else ans++;
    }
  }
  cout << ans;
  return 0;
}
