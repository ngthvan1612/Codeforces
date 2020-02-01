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
  int t;
  for (cin >> t; t--;) {
    int n, tmpn;
    cin >> n;
    tmpn = n;
    vector<ii> f;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        ii w(i, 0);
        while (n % i == 0) {
          w.second++;
          n /= i;
        }
        f.push_back(w);
      }
    }
    if (n > 1)
      f.push_back(ii(n, 1));
    if (int(f.size()) >= 3) {
      int a = 1, b = 1, c = 1;
      for (int i = 0; i < f[0].second; ++i)
        a *= f[0].first;
      for (int i = 0; i < f[1].second; ++i)
        b *= f[1].first;
      c = tmpn / (a * b);
      cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
    }
    else {
      if (int(f.size()) == 2) {
        bool ok = false;
        for (int i = 0, pi = f[0].first; i < f[0].second && !ok; ++i, pi *= f[0].first) {
          for (int j = 0, pj = f[1].first; j < f[1].second && !ok; ++j, pj *= f[1].first) {
            int w = tmpn / (pi * pj);
            if (w >= 2 && w != pi && w != pj) {
              ok = true;
              cout << "YES\n" << w << ' ' << pi << ' ' << pj << '\n';
            }
          }
        }
        if (!ok) {
          cout << "NO\n";
        }
      }
      else {
        if (f[0].second >= 6) {
          int a = 1, b = 1, c = 1;
          a = f[0].first;
          b = f[0].first * f[0].first;
          c = tmpn / (a * b);
          cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        }
        else cout << "NO\n";
      }
    }
  }
  return 0;
}
