#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 1;
const int mod = 1e9 + 7;
int n, k, res = 0;
struct edge {
	int v, color;
	edge(int _v = 0, int _color = 0) { v = _v; color = _color; }
};
bool vs[N];
vector<edge> g[N];
vector<int> sl;

int dfs(int u) {
	vs[u] = 1;
	int res = 1;
	for (edge e : g[u]) {
		if (!vs[e.v]) {
			if (e.color == 0)
				res = res + dfs(e.v);
		}
	}
	return res;
}

int Pow(int n, int k) {
	assert(k >= 0);
	int ans = 1;
	while (k) {
		if (k & 1)
			ans = 1LL * ans * n % mod;
		k >>= 1;
		n = 1LL * n * n % mod;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	memset(vs, 0, sizeof vs);
	for (int i = 1; i <= n - 1; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		g[u].push_back(edge(v, c));
		g[v].push_back(edge(u, c));
	}
	int Sum = 0;
	for (int i = 1; i <= n; ++i)
		if (!vs[i])
			Sum = (Sum + Pow(dfs(i), k)) % mod;
	cout << 1LL * (Pow(n, k) - Sum + mod) % mod;
	return 0;
}
