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

const int N = 1e5 + 5;
bool vs[2][N] = {0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, cnt[3] = {0};
  cin >> n >> q;
  while (q--) {
    int r, c;
    cin >> r >> c;
    r--;
    int e = 1, f = 2;
    if (r == 0) swap(e, f);
    if (vs[r][c]) {
      vs[r][c] = 0;
      if (vs[r ^ 1][c])
        cnt[0]--;
      if (vs[r ^ 1][c - 1])
        cnt[e]--;
      if (vs[r ^ 1][c + 1])
        cnt[f]--;
    }
    else {
      vs[r][c] = 1;
      if (vs[r ^ 1][c])
        cnt[0]++;
      if (vs[r ^ 1][c - 1])
        cnt[e]++;
      if (vs[r ^ 1][c + 1])
        cnt[f]++;
    }
    if (!cnt[0] && !cnt[1] && !cnt[2]) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
