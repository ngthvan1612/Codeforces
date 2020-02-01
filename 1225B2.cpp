#include <bits/stdc++.h
using namespace std
const int N = 2e5 + 5
int n, k, d, a[N], sz
map<int, int> cnt
void add(int x) 
  if (cnt[x] == 0) sz++
  cnt[x]++

void remove(int x) 
  if (cnt[x] == 1) sz--
  cnt[x]--

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int t
  for (cin >> t; t--;) 
    cin >> n >> k >> d
    for (int i = 1; i <= n; ++i
      cin >> a[i]
    sz = 0
    int ans = 1e9 + 7
    for (int i = 1; i <= n; ++i) 
      add(a[i])
      if (i - d >= 1
        remove(a[i - d])
      if (i >= d
        ans = min(ans, sz)
    
    cout << ans << '\n'
    cnt.clear()
  
  return 0

