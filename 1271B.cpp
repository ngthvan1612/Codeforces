#include <bits/stdc++.h>

using namespace std;

int n;
char a[203], b[203];
vector<int> ans;

int change(char w) {
  vector<int> p;
  for (int i = 1; i <= n; ++i)
    b[i] = a[i];
  int res = 0;
  for (int i = 1; i < n; ++i)
    if (b[i] != w) {
      p.push_back(i);
      b[i] = w;
      if (b[i + 1] == 'B')
        b[i + 1] = 'W';
      else
        b[i + 1] = 'B';
    }
  if (b[n] == w) {
    ans = p;
    return res;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a + 1;
  int r1 = change('W');
  int r2 = change('B');
  if (max(r1, r2) == -1) cout << -1;
  else {
    cout << ans.size() << '\n';
    for (int i : ans)
      cout << i << ' ';
  }
  return 0;
}
