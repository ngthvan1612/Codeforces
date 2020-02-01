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
  string tmp, s;
  cin >> tmp;
  for (int i = 0; i < int(tmp.length());) {
    int j = i;
    while (j < int(tmp.length()) && tmp[j] == tmp[i]) {
      s.push_back((tmp[i] == 'o' ? 'o' : 'w'));
      ++j;
    }
    if (tmp[i] == 'v') s.pop_back();
    i = j;
  }
  vector<ll> f(4, 0LL);
  f[0] = 1LL;
  for (int i = 0; i < int(s.length()); ++i) {
    if (s[i] == 'o') f[2] += f[1];
    else {
      f[3] += f[2];
      f[1] += f[0];
    }
  }
  cout << f[3];
  return 0;
}