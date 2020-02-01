#include <bits/stdc++.h>

using namespace std;

const int N = 503;
const int M = 1e5;
int a[N][N], r, c;
bool ip[M];

void init() {
  ip[0] = ip[1] = false;
  for (int i = 2; i < M; ++i)
    ip[i] = true;
  for (int i = 2; i * i < M; ++i)
    if (ip[i])
      for (int j = i * i; j < M; j += i)
        ip[j] = false;
}

int next(int cur) {
  cur++;
  while (cur < M && !ip[cur])
    cur++;
  return cur;
}

int main() {
  ios::sync_with_stdio(0);
  init();
  cin >> r >> c;
  if (r == 1 && c == 1) cout << 0;
  else {
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j)
        if (r < c) cout << i * (j + r) << ' ';
        else cout << j * (i + c) << ' ';
      cout << '\n';
    }
  }
  return 0;
}
