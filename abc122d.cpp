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

int fpow(int a, int p) {
  if (p == 0) return 1;
  if (p == 1) return a;
  int tmp = fpow(a, p / 2);
  tmp = mul(tmp, tmp);
  if (p & 1) tmp = mul(tmp, a);
  return tmp;
}

int n, dp[101][64], m;
bool ok[64][64], mk[64] = {0};
const char* p = "ACGT";

bool check(string s) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j)
      if (s[j] == 'A' && s[j + 1] == 'G' && s[j + 2] == 'C')
        return false;
    swap(s[i], s[i + 1]);
    for (int j = 0; j < 2; ++j)
      if (s[j] == 'A' && s[j + 1] == 'G' && s[j + 2] == 'C')
        return false;
    swap(s[i], s[i + 1]);
  }
  return true;
}

void init() {
  memset(ok, 0, sizeof ok);
  vector<string> w;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        string tmp;
        tmp.push_back(p[i]);
        tmp.push_back(p[j]);
        tmp.push_back(p[k]);
        w.push_back(tmp);
        if (!check(tmp))
          mk[int(w.size()) - 1] = true;
      }
    }
  }
  debug(w.size());
  int m = int(w.size());
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (w[i][1] == w[j][0] && w[i][2] == w[j][1]) {
        string tmp;
        tmp.push_back(w[i][0]);
        tmp.push_back(w[i][1]);
        tmp.push_back(w[i][2]);
        tmp.push_back(w[j][2]);
        ok[i][j] = check(tmp);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  init();
  memset(dp, 0, sizeof dp);
  for (int j = 0; j < 64; ++j)
    if (!mk[j])
      dp[3][j] = 1;
  for (int i = 4; i <= n; ++i)
    for (int pre = 0; pre < 64; ++pre)
      for (int nxt = 0; nxt < 64; ++nxt)
        if (ok[pre][nxt])
          dp[i][nxt] = sum(dp[i][nxt], dp[i - 1][pre]);
  int ans = 0;
  for (int j = 0; j < 64; ++j)
    ans = sum(ans, dp[n][j]);
  cout << ans;
  return 0;
}
