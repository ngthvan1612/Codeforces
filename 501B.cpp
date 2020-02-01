#include <bits/stdc++.h
using namespace std
typedef pair<int, int> ii
typedef long long ll
map<string, string> f
map<string, bool> mask
string dfs(string u) 
  if (f.find(u) == f.end()
    return u
  return dfs(f[u])

int main() 
  ios::sync_with_stdio(0)
  cin.tie(0)
  int n
  vector<string> ans
  for (cin >> n; n--;) 
    string a, b
    cin >> a >> b
    if (!mask[a]
      ans.push_back(a)
    mask[a] = mask[b] = true
    f[a] = b
  
  cout << ans.size() << '\n'
  for (int i = 0; i < int(ans.size()); ++i
    cout << ans[i] << ' ' << dfs(ans[i]) << '\n'
  return 0

