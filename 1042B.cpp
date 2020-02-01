#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int oo = 2e8 + 7
int dp[8], n
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 0; i < (1 << 3); ++i
    dp[i] = oo
  for (int i = 1; i <= n; ++i) 
    int mask = 0, c
    string s
    cin >> c >> s
    for (char w : s
      mask |= (1 << (w - 'A'))
    dp[mask] = min(dp[mask], c)
  
  int ans = +oo
  for (int s1 = 0; s1 < 8; ++s1
    for (int s2 = 0; s2 < 8; ++s2
      for (int s3 = 0; s3 < 8; ++s3
        if ((s1 | s2 | s3) == 7) 
          int res = 0
          if (s1) res += dp[s1]
          if (s2) res += dp[s2]
          if (s3) res += dp[s3]
          ans = min(ans, res)
        
  cout << (ans == oo ? -1 : ans) << '\n'
  return 0

