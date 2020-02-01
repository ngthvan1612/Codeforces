#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
struct DSU {
	int* d, *sz, n;
	DSU(const int& _n) {
		n = _n;
		d = new int[n + 1];
		sz = new int[n + 1];
		for (int i = 0; i <= n; ++i) {
			d[i] = i;
			sz[i] = 1;
		}
	}
	int Get(int u) { return d[u] = (u == d[u] ? u : Get(d[u])); }
	bool Merge(int u, int v) {
		u = Get(u);
		v = Get(v);
		if (u == v) return false;
		sz[v] += sz[u];
		d[u] = v;
		return true;
	}
	int GetSize(int u) { return sz[u = Get(u)]; }
};
int n, m, tmp[N];

int main() {
	scanf("%d%d", &n, &m);
	DSU dsu(n);
	while (m--) {
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; ++i) scanf("%d", &tmp[i]);
		for (int i = 1; i <= k; ++i) dsu.Merge(tmp[1], tmp[i]);
	}
	for (int i = 1; i <= n; ++i)
		printf("%d ", dsu.GetSize(i));
	return 0;
}

