#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
char a[N];
int n, dp[N];

int main() {
  scanf("%s", a + 1);
  n = int(strlen(a + 1));
  stack<int> st;
  int ans = 0, cnt = 1;
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == '(')
      st.push(i);
    else {
      if (!st.empty()) {       
        int len = i - st.top() + 1;
        if (dp[st.top() - 1] >= 0)
          len += dp[st.top() - 1];
        dp[i] = len;
        if (ans < len) {
          ans = len;
          cnt = 1;
        }
        else {
          if (ans == len)
            cnt++;
        }
        st.pop();
      }
    }
  }
  cout << ans << ' ' << cnt;
  return 0;
}
