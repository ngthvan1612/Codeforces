#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 0;
  srand(time(0));
  while (true) {
    int n = rand() % 100 + 3;
    int m = rand() % 100 + 3;
    m = min(m, n);
    int sum = n, ans = 0, cur = 0;
    while (sum) {      
      cur++;
      sum--;
      if (cur % m == 0)
        sum++;
    }
    int ans2 = n + 1 + (n - m) / (m - 1);
    if (cur != ans2) {
      printf("#%05d WA: [n, m] = [%d, %d], diff {%d, %d}\n", ++T, n, m, cur, ans2);
      break;
    }
    printf("#%05d AC: [n, m] = [%d, %d], ans = %d\n", ++T, n, m, ans2);
  }
  return 0;
}
