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

bool check(string s) {
  if (int(s.size()) <= 2) return true;
  if (s.find("AGC") != string::npos)
    return false;
  for (int i = 0; i < int(s.size()) - 1; ++i) {
    swap(s[i], s[i + 1]);
    if (s.find("AGC") != string::npos)
      return false;
    swap(s[i], s[i + 1]);
  }
  return true;
}

typedef pair<int, string> is;
map<is, int> mem;
const char* p = "ACGT";
int n, ans = 0;

int dfs(int i, string s) {
  if (mem.find(is(i, s)) != mem.end())
    return mem[is(i, s)];
  if (i == n)
    return mem[is(i, s)] = 1;
  int res = 0;
  for (int j = 0; j < 4; ++j) {
    string tmp = s;
    tmp.push_back(p[j]);
    if (check(tmp)) {
      if (tmp.size() == 4) {
        tmp.erase(0, 1);
      }
      res = sum(res, dfs(i + 1, tmp));
    }
  }
  return mem[is(i, s)] = res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < 4; ++i) {
    string s;
    s.push_back(p[i]);
    ans = sum(ans, dfs(1, s));
  }
  cout << ans;
  return 0;
}
