#include <bits/stdc++.h
using namespace std
typedef long long ll
int n, b, x[11]
ll Convert() 
  ll res = 0, base = 1
  for (int i = n; i >= 1; --i) 
    res += 1LL * x[i] * base
    base *= b
  
  return res

void read() 
  cin >> n >> b
  for (int i = 1; i <= n; ++i
    cin >> x[i]

int main() 
  ll a, b
  read()
  a = Convert()
  read()
  b = Convert()
  cerr << "DEBUG: [a, b] = [" << a << ", " << b << "]\n"
  if (a > b) cout << ">"
  else if (a == b) cout << "="
  else cout << "<"
  return 0

