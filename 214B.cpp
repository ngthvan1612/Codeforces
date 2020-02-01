#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int n, cnt[10] = {0}, sum = 0
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i) 
    int a
    cin >> a
    cnt[a]++
    sum += a
  
  if (!cnt[0]) cout << -1
  else 
    if (sum % 3 == 0) 
      if (cnt[0] == n) { cout << 0; return 0; 
      for (int i = 9; i >= 0; --i
        for (int v = 0; v < cnt[i]; ++v
          cout << i
    
    else 
      ///del 
      bool ok = false
      for (int i = 1; i < 9; ++i
        if ((sum - i) % 3 == 0 && cnt[i]) 
          cnt[i]--
          ok = true
          break
        
      ///del 
      if (!ok) 
        int w = 500, u = 10, v = 10
        for (int i = 1; i < 9; ++i
          for (int j = 1; j < 9; ++j
            if (cnt[i] && cnt[j] && cnt[i] + (i != j) * cnt[j] >= 2 && (sum - i - j) % 3 == 0) 
              if (w > i + j && max(u, v) >= max(i, j)) 
                w = i + j
                u = i
                v = j
              
            
        cnt[u]--
        cnt[v]--
      
      bool diff = false
      for (int i = 1; i <= 9; ++i
        if (cnt[i]
          diff = true
      if (!diff) cout << 0
      else 
        for (int i = 9; i >= 0; --i
          for (int v = 0; v < cnt[i]; ++v
            cout << i
      
    
  
  return 0

