#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, cnt[3];
char a[N];

int main() {
  scanf("%d\n%s", &n, a + 1);
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i)
    cnt[a[i] - '0']++;
  for (int i = 1; i <= n; ++i) {
    int u = a[i] - '0';
    for (int v = 0; v <= 2 && u > v; ++v)
      if (cnt[u] > n / 3 && cnt[v] < n / 3) {
        cnt[u]--;
        cnt[v]++;
        a[i] = v + '0';
        break;
      }
  }
  for (int i = n; i >= 1; --i) {
    int u = a[i] - '0';
    for (int v = 2; v >= 0 && v > u; --v)
      if (cnt[u] > n / 3 && cnt[v] < n / 3) {
        cnt[u]--;
        cnt[v]++;
        a[i] = v + '0';
        break;
      }    
  }
  cout << a + 1;
  return 0;
}
