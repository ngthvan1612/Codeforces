///created: 9/Jul/2019 14:46:42

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int modulo = 1e9 + 7;

#ifdef LOCAL_DEBUG_NTV1612
template<class __Ty>
string to_string(__Ty a) {
	string res = "[ ";
	bool f = true;
	for (auto &p : a) { res += (f ? string("") : string(", ")) + to_string(p); f = false;	}
	return res + " ]";
}
void _debug() { fprintf(stderr, "\n"); }
template<typename __Ty_head, typename... __Ty_tail>
void _debug(__Ty_head head, __Ty_tail... tail) { fprintf(stderr, "%s ", to_string(head).c_str()); _debug(tail...); }
#define debug(...) fprintf(stderr, "DEBUG [%s]: ", #__VA_ARGS__), _debug(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class __Ty> bool mini(__Ty& a, __Ty b) { return a > b ? ((a = b) | 1) : (0); }
template<class __Ty> bool maxi(__Ty& a, __Ty b) { return a < b ? ((a = b) | 1) : (0); }
template<class __Ty> __Ty add(__Ty a, __Ty b) { return (a + b) % (__Ty(modulo)); }
template<class __Ty> __Ty sub(__Ty a, __Ty b) { __Ty m(modulo); return ((a - b) % m + m) % m; }

const int N = 2e5 + 5;
int n, ans[N], p[N];
vector<int> g[N];

int dfs(int u) {
	////coloring
	int cur_color = 1;
	for (int v : g[u])
		if (v != p[u]) {
			while (cur_color == ans[u] || cur_color == ans[p[u]])
				cur_color++;			
			ans[v] = cur_color++;
		}
	int res = cur_color - 1;
	///travel
	for (int v : g[u])
		if (v != p[u]) {
			p[v] = u;
			res = max(res, dfs(v));
		}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	p[1] = p[0] = 0;
	ans[0] = -1;
	ans[1] = 1;
	cout << dfs(1) << '\n';
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}
