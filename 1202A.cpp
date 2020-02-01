#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int t
  for (cin >> t; t--;) 
    string x, y
    cin >> x >> y
    reverse(x.begin(), x.end())
    reverse(y.begin(), y.end())
    int py, px
    for (int i = 0; i < int(y.length()); ++i
      if (y[i] == '1') 
        py = i
        break
      
    for (int i = py; i < int(x.length()); ++i
      if (x[i] == '1') 
        px = i
        break
      
    cout << px - py << '\n'
  
  return 0

