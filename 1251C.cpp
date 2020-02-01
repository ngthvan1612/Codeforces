#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
const int N = 3e5 + 5
int n
char a[N]
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int t
  for (cin >> t; t--;) 
    cin >> a + 1
    n = int(strlen(a + 1))
    stack<char> odd, even
    for (int i = n; i >= 1; --i
      if ((a[i] - '0') % 2
        odd.push(a[i])
      els
        even.push(a[i])
    for (int i = 1; i <= n; ++i) 
      if (even.empty()) 
        cout << odd.top()
        odd.pop()
      
      else if (odd.empty()) 
        cout << even.top()
        even.pop()
      
      else 
        cout << min(even.top(), odd.top())
        if (even.top() > odd.top()
          odd.pop()
        els
          even.pop()
      
    
    cout << '\n'
  
  return 0

