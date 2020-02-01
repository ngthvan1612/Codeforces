#include <bits/stdc++.h>

using namespace std;

vector<int> fact(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      res.push_back(i);
      if (i * i != x)
        res.push_back(x / i);
    }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  int a, b, n, low, high, g;
  scanf("%d%d%d", &a, &b, &n);
  vector<int> fa = fact(a), fb = fact(b);
  vector<int> fc;
  for (int i = 0, j = 0; i < int(fa.size()); ++i) {
    while (j < int(fb.size()) && fa[i] > fb[j])
      ++j;
    if (j < int(fb.size()) && fa[i] == fb[j]) {
      fc.push_back(fa[i]);
    }
  }
  while (n--) {
    scanf("%d %d", &low, &high);
    int l = 0, r = int(fc.size()) - 1, k = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (fc[mid] <= high) {
        l = mid + 1;
        if (fc[mid] >= low)
          k = fc[mid];
      }
      else
        r = mid - 1;
    }
    printf("%d\n", k);
  }
  return 0;
}
