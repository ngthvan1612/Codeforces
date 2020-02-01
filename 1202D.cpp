#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int N = 1e5 + 5
ll num[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  for (int i = 0; i < N; ++i
      num[i] = 1LL * i * (i - 1) / 2
  int t
  for (cin >> t; t--;) 
      int n, fmax = 0
      cin >> n
      vector<ll> f
      for (int i = N - 1; i >= 2; --i
          if (num[i] <= n) 
              fmax = max(fmax, i)
              n -= num[i]
              f.push_back(i)
          
      while (n) 
          n--
          f.push_back(2)
      
      cout << 1
      for (int i = 1; i <= fmax; ++i) 
          cout << 3
          while (!f.empty() && f.back() == i) 
              cout << 7
              f.pop_back()
          
      
      cout << '\n'
  
  return 0

