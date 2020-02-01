///created: 3/Jul/2019 23:15:22

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

int a[401][401], n, m;
int dist[401];

int bfs(int s, int t, int f) {
	queue<int> Q;
	Q.push(s);
	memset(dist, -1, sizeof dist);
	dist[s] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int v = 1; v <= n; ++v)
			if (a[u][v] == f && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
	}
	return dist[t];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		a[i][i] = -1;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u][v] = a[v][u] = 1;
	}
	int r1 = bfs(1, n, 1);
	int r2 = bfs(1, n, 0);
	if (r1 < 0 || r2 < 0) cout << -1;
	else cout << max(r1, r2);
	return 0;
}
