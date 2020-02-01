#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
#define fi firs
#define se secon
typedef long long ll
const int N = 4e5 + 5
ii a[N]
int n, ans[N]
string s
int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  cin >> n
  for (int i = 1; i <= n; ++i) 
    cin >> a[i].fi
    a[i].se = i
  
  cin >> s
  sort(a + 1, a + 1 + n)
  int sp = 0, sn = 0
  stack<int> st
  for (int i = 0; i < 2 * n; ++i
    if (s[i] == '0') {     
      sn++
      ans[i + 1] = a[sn].se
      st.push(a[sn].se)
    
    else 
      ans[i + 1] = st.top()
      st.pop()
    
  for (int i = 1; i <= 2 * n; ++i
    cout << ans[i] << ' '
  return 0

