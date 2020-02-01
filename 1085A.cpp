#include <bits/stdc++.h
using namespace std
int main() 
  string a, b
  cin >> a
  int i = 0, j = int(a.size()) - 1, w = int(a.length()) % 2
  while (i <= j) 
    if (w) 
      b.push_back(a[i])
      ++i
    
    else 
      b.push_back(a[j])
      --j
    
    w ^= 1
  
  reverse(b.begin(), b.end())
  cout << b
  return 0

