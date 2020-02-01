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
    int n;
    ll sum = 0;
    cin >> n;
    vector<int> a(n);
    bool pos = false;
    for (int &x : a) {
      cin >> x;
      sum += x;
      if (x > 0) pos = true;
    }
    bool ok = true;
    for (int i = 0; i < n;) {
      if (a[i] < 0) continue;
      int j = i;
      ll res = 0;
      while (j < n && a[j] >= 0) {
        res += a[j];
        ++j;
      }
      if (res >= sum) {
        ok = false;
        break;
      }
      i = j;
    }
    if (!pos) {
      cout << "NO\n";
    }
    else if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
