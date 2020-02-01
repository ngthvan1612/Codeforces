#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, sumTime, mi[31], ma[31], tmp2 = 0, tmp1 = 0;
  cin >> n >> sumTime;
  for (int i = 1; i <= n; ++i) {
    cin >> mi[i] >> ma[i];
    tmp2 += ma[i];
    tmp1 += mi[i];
  }
  if (tmp2 < sumTime || tmp1 > sumTime) cout << "NO";
  else {
    cout << "YES\n";
    sumTime -= tmp1;
    for (int i = 1; i <= n; ++i) {
      int tmp = min(sumTime, ma[i] - mi[i]);
      cout << tmp + mi[i] << ' ';
      sumTime -= tmp;
    }
  }
  return 0;
}
