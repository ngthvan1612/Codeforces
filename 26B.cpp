#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 3;
char a[N];
int n;

struct node {
  int open, close, res;
  node(int _o = 0, int _c = 0, int _r = 0) {
    open = _o;
    close = _c;
    res = _r;
  }
};

node get(int l, int r) {
  if (l == r) {
    if (a[l] == '(')
      return node(1, 0, 0);
    return node(0, 1, 0);
  }
  else {
    int mid = (l + r) / 2;
    node L = get(l, mid);
    node R = get(mid + 1, r);
    node ans(0, 0, L.res + R.res);
    int tmp = min(L.open, R.close);
    ans.res += 2 * tmp;
    ans.open = L.open - tmp + R.open;
    ans.close = L.close + R.close - tmp;
    return ans;
  }
}

int main() {
  scanf("%s", a + 1);
  n = int(strlen(a + 1));
  cout << get(1, n).res;
  return 0;
}
