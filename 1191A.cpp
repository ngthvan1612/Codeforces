#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int rev[4] = { 0, 3, 1, 2 }, x, ans = 0, cur
  char hp[4] = { 'D', 'A', 'C', 'B' }
  char res
  cin >> x
  cur = x % 4
  for (int i = 0; i <= 2;  ++i
    if (rev[cur] <= rev[(x + i) % 4]) 
      cur = (x + i) % 4
      ans = i
      res = hp[cur]
    
  cout << ans << ' ' << res
  return 0

