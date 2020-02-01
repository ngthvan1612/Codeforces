///created: 12/Jul/2019 19:14:18

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
int n, m, order[N], cur;
bool vs[N];
vector<int> g[N];

void dfs(int u) {
	vs[u] = 1;
	order[++cur] = u;
	for (int v : g[u])
		if (!vs[v])
			dfs(v);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end());
	memset(vs, 0, sizeof vs);
	cur = 0;
	priority_queue<int, vector<int>, greater<int> > heap;
	heap.push(1);
	vs[1] = 1;
	while (!heap.empty()) {
		int u = heap.top();
		heap.pop();
		order[++cur] = u;
		for (int v : g[u])
			if (!vs[v]) {
				heap.push(v);
				vs[v] = 1;
			}
	}
	for (int i = 1; i <= n; ++i)
		cout << order[i] << ' ';
	return 0;
}
