///created: 7/Jun/2019 14:18:42

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';
template<class __Ty> bool minimize(__Ty& a, __Ty b) {
	if (a > b) { a = b; return true; }
	return false;
}
template<class __Ty> bool maximize(__Ty& a, __Ty b) {
	if (a < b) { a = b; return true; }
	return false;
}

const int N = 1e5 + 1;
vector<int> g[N];
int n, m, c[N];
bool vs[N] = {0};

int dfs(int u) {
	int res = c[u];
	vs[u] = 1;
	for (int v : g[u])
		if (!vs[v])
			res = min(res, dfs(v));
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!vs[i])
			ans += dfs(i);
	cout << ans;
	return 0;
}
