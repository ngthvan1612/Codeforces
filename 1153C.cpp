#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
char a[N];
int n, dp[N];

int main() {
  scanf("%d\n%s", &n, a + 1);
  if (n % 2) {
    printf(":(");
    return 0;
  }
  stack<int> st;
  int open = 0;
  bool ans = true;
  for (int i = 1; i <= n; ++i)
    if (a[i] == '(') open++;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == '(') {
      st.push(i);
    }
    else if (a[i] == ')') {
      if (st.empty()) {
        ans = false;
        break;
      }
      else st.pop();
    }
    else {
      if (open < n / 2) {
        open++;
        st.push(i);
        a[i] = '(';
      }
      else {
        if (st.empty()) {
          ans = false;
          break;
        }
        else {
          a[i] = ')';
          st.pop();
        }
      }
    }
  }
  ///cerr << "DEBUG: " << a + 1 << '\n';
  if (st.empty() && ans) {
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == '(') dp[i] = dp[i - 1] + 1;
      else dp[i] = dp[i - 1] - 1;
      if (dp[i] == 0 && i != n) {
        ans = false;
        break;
      }
    }
    if (ans) printf("%s", a + 1);
    else printf(":(");
  }
  else printf(":(");
  return 0;
}
