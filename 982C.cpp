#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, p[N], sz[N], lf;
bool rem[N];
vector<int> g[N];

int dfs(int u) {
	sz[u] = 1;
	int ans = 0;
	for (int v : g[u])
		if (v != p[u]) {
			p[v] = u;
			ans += dfs(v);
			if (sz[v] % 2 == 0 && (lf - sz[v]) % 2 == 0 && !rem[v]) {
				fprintf(stderr, "REMOVE: (%d, %d)\n", u, v);
				ans++;
				lf -= sz[v];
				sz[v] = 1e9 + 7;
				rem[v] = true;
			}
			else
				sz[u] += sz[v];
		}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n % 2) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(p, 0, sizeof p);
	memset(sz, 0, sizeof sz);
	memset(rem, 0, sizeof rem);
	lf = n;
	cout << dfs(1);
	return 0;
}
