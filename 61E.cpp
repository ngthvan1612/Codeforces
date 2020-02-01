#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
typedef pair<int, int> ii;
typedef long long ll;
ii tmp[N];
int n, a[N];
ll bit[N][3];

void update(int pos, ll val, int s) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i][s] += val;
}

ll get(int pos, int s) {
  ll res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i][s];
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> tmp[i].first;
    tmp[i].second = i;
  }
  sort(tmp + 1, tmp + 1 + n);
  for (int i = 1, s = 1, cur = tmp[1].first; i <= n; ++i) {
    if (cur != tmp[i].first) {
      cur = tmp[i].first;
      s++;
    }
    a[tmp[i].second] = s;
  }
  reverse(a + 1, a + 1 + n);
  memset(bit, 0, sizeof bit);
  for (int i = 1; i <= n; ++i) {
    update(a[i], get(a[i] - 1, 1), 2);
    update(a[i], get(a[i] - 1, 0), 1);
    update(a[i], 1, 0);
  }
  cout << get(n, 2);
  return 0;
}
