#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 2e9 + 7;
const int N = 1e5 + 5;
int trie[30 * N][2], cnt[30 * N][2], sz;
int dp[30 * N], ans[30 * N];
int n, a[N];

void insert_trie(int x) {
  int cur = 0, v;
  for (int i = 30; i >= 0; --i) {
    v = (x >> i) & 1;
    if (trie[cur][v] < 0) {
      trie[cur][v] = ++sz;
    }
    cur = trie[cur][v];
  }
  cnt[cur][v]++;
}

void dfs0(int pos, int val, int base) {
  if (trie[pos][0] < 0 && trie[pos][1] < 0) {
    for (int k = 0; k < cnt[pos][val % 2]; ++k)
      printf("%d\n", val);
  }
  else {
    for (int k = 0; k < 2; ++k)
      if (trie[pos][k])
        dfs0(trie[pos][k], val + k * base, base / 2);
  }
}

void dfs1(int pos, int base) {
  if (pos < 0) {
    dp[pos] = 0;
  }
  else {
    int l = trie[pos][0], r = trie[pos][1];
    dfs1(l, base / 2);
    dfs1(r, base / 2);
    if (l < 0 && r < 0)
      return;
    if (l < 0) {
      dp[pos] = dp[r];
      ans[pos] = 1 * base + ans[r];
    }
    else if (r < 0) {
      dp[pos] = dp[l];
      ans[pos] = 0 * base + ans[l];
    }
    else {
      int r0 = 1 * base + dp[r];
      int r1 = 1 * base + dp[l];
      dp[pos] = min(r0, r1);
      if (r0 <= r1) {
        ans[pos] = 0 * base + ans[l];
      }
      else {
        ans[pos] = 1 * base + ans[r];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(trie, -1, sizeof trie);
  memset(cnt, 0, sizeof cnt);
  memset(dp, 0, sizeof dp);
  memset(ans, 0, sizeof ans);
  sz = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    insert_trie(a[i]);    
  }
  dfs1(0, 1 << 30);
  cout << dp[0];
  return 0;
}
