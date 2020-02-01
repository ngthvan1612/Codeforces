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
bool vs[N] = {0};
vector<string> ans;

void dfs(vector<int> a) {
  if (int(a.size()) == 1) {
    if (a[0] == 24) {
      cout << "YES\n";
      for (string v : ans)
        cout << v << '\n';
      exit(0);
    }
  }
  else {
    for (int i = 0; i < int(a.size()) - 1; ++i) {
      for (int j = i + 1; j < int(a.size()); ++j) {
        vector<int> tmp;
        for (int k = 0; k < int(a.size()); ++k)
          if (k != i && k != j)
            tmp.push_back(a[k]);
        string ai = to_string(a[i]);
        string aj = to_string(a[j]);
        tmp.push_back(a[i] * a[j]);
        ans.push_back(ai + " * " + aj + " = " + to_string(a[i] * a[j]));
        dfs(tmp);
        ans.pop_back();
        tmp.pop_back();
        tmp.push_back(a[i] - a[j]);
        ans.push_back(ai + " - " + aj + " = " + to_string(a[i] - a[j]));
        dfs(tmp);
        ans.pop_back();
        tmp.pop_back();
        tmp.push_back(a[i] + a[j]);
        ans.push_back(ai + " + " + aj + " = " + to_string(a[i] + a[j]));
        dfs(tmp);
        ans.pop_back();
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, a, b, s;
  cin >> n;
  if (n <= 6) {
    vector<int> a;
    for (int i = 1; i <= n; ++i)
      a.push_back(i);
    dfs(a);
    cout << "NO\n";
    return 0;
  }
  s = n * (n + 1) / 2;
  ///a + b = s, a - b = 24
  a = (s + 24) / 2;
  b = s - a;
  for (ll i = n; i >= 1; --i)
    if (a >= i) {
      a -= i;
      vs[i] = true;
    }
  debug(a);
  assert(a == 0);
  ll tb = 0;
  cout << "YES\n";
  for (int i = n; i >= 1; --i) {
    if (s % 2 != 0 && i == 1) continue;
    if (vs[i]) {
      if (a == 0) {
        a = i;
      }
      else {
        cout << a << " + " << i << " = " << a + i << '\n';
        a += i;
      }
    }
    else {
      if (tb == 0) {
        tb = i;
      }
      else {
        cout << tb << " + " << i << " = " << tb + i << '\n';
        tb += i;
      }
    }
  }
  cout << a << " - " << tb << " = " << a - tb << '\n';
  if (s & 1)
    cout << 24 << " * " << 1 << " = " << 24;
  return 0;
}
