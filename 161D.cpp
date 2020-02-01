#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 1;
const int K = 5e2 + 1;
typedef long long int ll;

int n, k, cnt[N][K], p[N];
vector<int> g[N];
ll ans;

void dfs(int u) {
	cnt[u][0] = 1;
	for (int v : g[u])
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
			for (int j = 0; j <= k; ++j) {
				if (k - j - 1 >= 0)
					ans += 1LL * cnt[u][j] * cnt[v][k - j - 1];
				if (j > 0)
					cnt[u][j] += cnt[v][j - 1];
			}
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(cnt, 0, sizeof cnt);
	memset(p, 0, sizeof p);
	cin >> n >> k;
	for (int i = 1; i <= n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans = 0;
	dfs(1);
	cout << ans;
	return 0;
}
