///created: 9/Jul/2019 20:11:41

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

const int N = 1e5 + 5;
int n, init[N], goal[N], parent[N], flip[N];
vector<int> g[N];
vector<int> ans;

void dfs(int u) {
	flip[u] = flip[parent[parent[u]]];
	init[u] ^= flip[u];
	debug(u, init[u], goal[u]);
	if (init[u] != goal[u]) {
		init[u] ^= 1;
		flip[u] ^= 1;
		ans.push_back(u);
	}
	for (int v : g[u])
		if (v != parent[u]) {
			parent[v] = u;
			dfs(v);
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		cin >> init[i];
	for (int i = 1; i <= n; ++i)
		cin >> goal[i];
	parent[1] = parent[0] = 0;
	flip[0] = 0;
	dfs(1);
	cout << ans.size() << '\n';
	for (int v : ans)
		cout << v << '\n';
	return 0;
}
