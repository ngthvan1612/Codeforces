#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<int> res;
  s += 'W';
  for (int i = 0, cnt = 0; i < n + 1; ++i) {
    if (s[i] == 'W') {
      if (cnt != 0) {
        res.push_back(cnt);
        cnt = 0;
      }
    }
    else cnt++;
  }
  cout << int(res.size()) << '\n';
  for (int v : res)
    cout << v << ' ';
  return 0;
}
