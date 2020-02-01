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
vector<int> g[N];
int n, m, c[N];
vector< vector<int> > scc;

///Tarjan
int low[N], num[N], nscc = 0;
stack<int> st;
void dfs(int u) {
  low[u] = num[u] = ++nscc;
  st.push(u);
  for (int v : g[u])
    if (num[v]) low[u] = min(low[u], num[v]);
    else {
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  if (num[u] == low[u]) {
    vector<int> tmp;
    int v;
    do {
      v = st.top(); st.pop();
      tmp.push_back(v);
      low[v] = num[v] = +oo;
    }
    while (u != v);
    scc.push_back(tmp);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> c[i];
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  memset(low, 0, sizeof low);
  memset(num, 0, sizeof num);
  for (int i = 1; i <= n; ++i)
    if (!num[i])
      dfs(i);
  int ans = 1;
  ll res = 0;
  for (int i = 0; i < int(scc.size()); ++i) {
    int mz = oo, cnt = 0;
    for (int v : scc[i]) {
      if (c[v] < mz) {
        mz = c[v];
        cnt = 1;
      }
      else if (c[v] == mz) cnt++;
    }
    res += mz;
    ans = mul(ans, cnt);
  }
  cout << res << ' ' << ans;
  return 0;
}
