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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n <= 3) {
    cout << "NO\n";
    return 0;
  }
  else {
    cout << "YES\n";
    int b;
    if (n % 2 == 0) {
      cout << "1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n";
      b = 4;
    }
    else {
      cout << "1 * 2 = 2\n3 + 4 = 7\n7 + 5 = 12\n12 * 2 = 24\n";
      b = 5;
    }
    for (int i = b + 1; i <= n; i += 2) {
      cout << i + 1 << " - " << i << " = " << 1 << '\n';
      cout << 24 << " * " << 1 << " = " << 24 << '\n';
    }
  }
  return 0;
}
