#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 7;
typedef long long ll;
int t, a, b, rev[N];
ll dp[N], cnt[N];
bool ip[N];

void init() {
  ip[0] = 0;
  ip[1] = 0;
  cnt[1] = 1;
  for (int i = 2; i < N; ++i) {
    ip[i] = 1;
    rev[i] = 0;
    cnt[i] = 0;
  }
  for (int i = 2; i * i < N; ++i)
    if (ip[i]) {
      cnt[i] = 1;
      for (int j = i * i; j < N; j += i) {
        ip[j] = 0;
        if (!rev[j]) {
          rev[j] = i;
        }
      }
    }
  for (int i = 4; i < N; ++i)
    if (!ip[i])
      cnt[i] = 1 + cnt[i / rev[i]];
    else
      cnt[i] = 1;
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i < N; ++i)
    dp[i] = dp[i - 1] + cnt[i];
}

int main() {
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t; t--;) {
    cin >> a >> b;
    cout << dp[a] - dp[b] << '\n';
  }
  return 0;
}
