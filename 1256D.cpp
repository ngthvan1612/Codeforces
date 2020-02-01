#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
typedef long long ll;
ll k;
int q, n;
char a[N];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> q; q--;) {
    cin >> n >> k >> a + 1;
    stack<int> st;
    for (int i = n; i >= 1; --i)
      if (a[i] == '0')
        st.push(i);
    for (int i = 1; i <= n; ++i) {
      while (!st.empty() && st.top() <= i)
        st.pop();
      if (a[i] == '1' && !st.empty()) {
        if (st.top() - i <= k) {
          k -= st.top() - i;
          swap(a[st.top()], a[i]);
          st.pop();
        }
      }
    }
    cout << a + 1 << '\n';
  }
  return 0;
}
