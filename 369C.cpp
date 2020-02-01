#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
struct edge {
	int v, t;
	edge(int _v = 0, int _t = 0) {
		v = _v;
		t = _t;
	}
};
vector<edge> g[N];
vector<int> ans;
int p[N], cnt[N];
int n, m;

void dfs(int u) {
	bool ok = true;
	for (edge e : g[u])
		if (e.v != p[u]) {
			p[e.v] = u;
			if (e.t == 2) {
				cnt[e.v]++;
				ok = false;
			}
			dfs(e.v);
			if (cnt[e.v] > 0)
				ok = false;
			cnt[u] += cnt[e.v];
		}
	if (ok && cnt[u] > 0)
		ans.push_back(u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		g[x].push_back(edge(y, t));
		g[y].push_back(edge(x, t));
	}
	memset(p, -1, sizeof p);
	p[1] = 0;
	p[0] = 0;
	dfs(1);
	cout << ans.size() << '\n';
	for (int v : ans)
		cout << v << ' ';
	return 0;
}
