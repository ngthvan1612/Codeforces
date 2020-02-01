#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  set<int> st;
  for (cin >> n; n--;) {
    int a;
    cin >> a;
    if (a != 0)
      st.insert(a);
  }
  cout << int(st.size());
  return 0;
}
