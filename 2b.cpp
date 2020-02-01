#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;
const int modulo = 1e9 + 7;
template<typename T>
inline T sum(const T& a, const T& b) { return T((a % modulo + b % modulo) % modulo); }
template<typename T>
inline T mul(const T& a, const T& b) { return T((1LL * (a % (1LL * modulo)) * (b % (1LL * modulo))) % (1LL * modulo)); }
string to_string(string a) { return "\"" + a + "\""; }
#ifdef __LOCAL_DEBUG
#define debug(args...) { string __out = #args; replace(__out.begin(), __out.end(), ',', ' '); stringstream __out_ss(__out);\
istream_iterator<string> __it(__out_ss); _debug(__it, args); }
void _debug(istream_iterator<string> it) { }
template<typename T, typename... Args>
void _debug(istream_iterator<string> it, T a, Args... args){ cerr << *it << " = " << to_string(a) << '\n'; _debug(++it, args...); }
#else
#define debug(...)
#endif

const int N = 1e3 + 5;
int n, a[N][N], c[N][N][2], f[N][N], r0, c0;
ii trace[N][N];
string p[2];

int calc(int val, int base) {
  int res = 0;
  if (val == 0) return 0;
  while (val % base == 0) {
    val /= base;
    res++;
  }
  return res;
}

int dp(int w) {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      f[i][j] = +oo;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int q = 0;
      if (i == 1 && j == 1) f[i][j] = 0;
      else if (i == 1) f[i][j] = f[i][j - 1], q = 1;
      else if (j == 1) f[i][j] = f[i - 1][j], q = 2;
      else {
        if (f[i - 1][j] < f[i][j - 1]) f[i][j] = f[i - 1][j], q = 2;
        else f[i][j] = f[i][j - 1], q = 1;
      }
      f[i][j] += c[i][j][w];
      if (a[i][j] == 0)
        f[i][j] += +oo / 1000;
      if (q == 0) trace[i][j] = ii(i, j);
      else if (q == 1) trace[i][j] = ii(i, j - 1);
      else trace[i][j] = ii(i - 1, j);
    }
  }
  int i = n, j = n;
  while (i != 1 || j != 1) {
    int ri = i, rj = j;
    if (trace[i][j].first == i - 1) p[w].push_back('D');
    else p[w].push_back('R');
    i = trace[ri][rj].first;
    j = trace[ri][rj].second;
  }
  reverse(p[w].begin(), p[w].end());
  return f[n][n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(c, 0, sizeof c);
  r0 = -1, c0 = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      c[i][j][0] = calc(a[i][j], 2);
      c[i][j][1] = calc(a[i][j], 5);
      if (a[i][j] == 0) {
        r0 = i;
        c0 = j;
      }
    }
  }
  int res0 = dp(0), res1 = dp(1);
  if (min(res0, res1) > 0 && r0 > 0) {
    cout << 1 << '\n';
    for (int i = 1; i < r0; ++i)
      cout << 'D';
    for (int j = 1; j < c0; ++j)
      cout << 'R';
    for (int i = r0 + 1; i <= n; ++i)
      cout << 'D';
    for (int i = c0 + 1; i <= n; ++i)
      cout << 'R';
  }
  else {
    if (res0 < res1) cout << res0 << '\n' << p[0];
    else cout << res1 << '\n' << p[1];
  }
  return 0;
}
