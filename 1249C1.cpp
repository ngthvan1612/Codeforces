#include <bits/stdc++.h
using namespace std
typedef long long ll
const int N = 1e5 + 5
ll p[40]
bool dp[N]
int n, q
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  p[0] = 1
  for (int i = 1; i <= 37; ++i
    p[i] = p[i - 1] * 3
  for (int state = 0; state < (1 << 11); ++state) 
    int sum = 0
    for (int j = 0; j < 11; ++j
      if ((state >> j) & 1
        sum += int(p[j])
    if (sum < N
      dp[sum] = true
  
  for (cin >> q; q--;) 
    cin >> n
    while (!dp[n]) ++n
    cout << n << '\n'
  
  return 0

