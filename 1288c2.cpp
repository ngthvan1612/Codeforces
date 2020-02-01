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

const int N = 2e3 + 1;
int fact[N];
int n, m;

int fpow(int a, int p) {
  if (p == 0) return 1;
  int tmp = fpow(a, p / 2);
  tmp = mul(tmp, tmp);
  if (p & 1) tmp = mul(tmp, a);
  return tmp;
}

int inv(int x) { return fpow(x, modulo - 2); }

int nCr(int n, int r) {
  return mul(fact[n], mul(inv(fact[r]), inv(fact[n - r])));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i < N; ++i)
    fact[i] = mul(fact[i - 1], i);
  cout << nCr(n + 2 * m - 1, 2 * m);
  return 0;
}
