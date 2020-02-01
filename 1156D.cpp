#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 1;
int d[2][N], n, sz[2][N];

int get(int u, int w) {
	if (d[w][u] == u) return u;
	return d[w][u] = get(d[w][u], w);
}

void merge(int u, int v, int w) {
	u = get(u, w);
	v = get(v, w);
	if (u == v) return;
	d[w][u] = v;
	sz[w][v] += sz[w][u];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		d[0][i] = d[1][i] = i;
		sz[0][i] = sz[1][i] = 1;
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		merge(u, v, w);
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[0][i] == i) res += 1LL * sz[0][i] * (sz[0][i] - 1);
		if (d[1][i] == i) res += 1LL * sz[1][i] * (sz[1][i] - 1);
		res += 1LL * (sz[0][get(i, 0)] - 1) * (sz[1][get(i, 1)] - 1);
	}
	cout << res;
	return 0;
}
