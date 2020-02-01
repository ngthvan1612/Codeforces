#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t, p;
  int flip = 0;
  cin >> s >> t;
  int n = int(s.length());
  for (int i = 0; i < n; ++i)
    if (s[i] == t[i])
      p.push_back(s[i]);
    else {
      if (flip) p.push_back(s[i]);
      else p.push_back(t[i]);
      flip ^= 1;
    }
  int r1 = 0, r2 = 0;
  for (int i = 0; i < n; ++i)
    r1 += (s[i] != p[i]), r2 += (t[i] != p[i]);
  if (flip) cout << "impossible";
  else { assert(r1 == r2); cout << p; }
  return 0;
}
