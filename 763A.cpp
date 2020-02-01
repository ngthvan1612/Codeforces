///created: 9/Jul/2019 10:40:37

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
int n, d[N], c[N], sz[N];
vector<int> g[N];

int get(int u) { return d[u] = (u == d[u] ? u : get(d[u])); }

void unite(int u, int v) {
	u = get(u);
	v = get(v);
	if (u == v) return;
	d[u] = v;
	sz[v] += sz[u];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		d[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int u = 1; u <= n; ++u)
		for (int v : g[u])
			if (c[u] == c[v])
				unite(u, v);
	int ans = -1;
	for (int u = 1; u <= n; ++u) {
		int cnt = 0;
		bool same_color = false;
		set<int> vs;
		for (int v : g[u]) {
			if (vs.find(get(v)) == vs.end()) {
				if (c[u] == c[v])
					same_color = true;
				cnt += sz[get(v)];
				vs.insert(get(v));
			}
		}
		if (same_color) cnt--;
		if (cnt == n - 1)
			ans = u;
	}
	if (ans == -1) cout << "NO";
	else cout << "YES\n" << ans;
	return 0;
}
