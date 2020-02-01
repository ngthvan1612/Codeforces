///created: 7/Jul/2019 16:52:19

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
int n, m, trace[N];
ll dist[N];
struct edge {
	int v;
	ll c;
	edge(int a = 0, ll b = 0) {
		v = a;
		c = b;
	}
};
bool operator>(const edge& l, const edge& r) { return l.c > r.c || (l.c == r.c && l.v > r.v); }
vector<edge> g[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(edge(v, c));
		g[v].push_back(edge(u, c));
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = 1e18;
		trace[i] = 0;
	}
	dist[1] = 0;
	priority_queue<edge, vector<edge>, greater<edge> > heap;
	heap.push(edge(1, 0LL));
	while (!heap.empty()) {
		edge t = heap.top();
		heap.pop();
		if (dist[t.v] < t.c)
			continue;
		for (edge e : g[t.v]) {
			if (dist[e.v] > dist[t.v] + e.c) {
				trace[e.v] = t.v;
				heap.push(edge(e.v, dist[e.v] = dist[t.v] + e.c));
			}
		}
	}
	if (dist[n] == 1e18)
		cout << -1;
	else {
		vector<int> path;
		while (n) {
			path.push_back(n);
			n = trace[n];
		}
		reverse(path.begin(), path.end());
		for (int v : path)
			cout << v << ' ';
	}
	return 0;
}
