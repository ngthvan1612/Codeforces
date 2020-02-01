///created: 3/Jun/2019 22:09:18

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define db(x) cerr << "debug: " << #x << " = " << x << '\n';

int n, m, k;
bool a[100005] = {0};
vector<ii> g[100005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(ii(v, c));
		g[v].push_back(ii(u, c));
	}
	for (int i = 1; i <= k; ++i) {
		int t;
		cin >> t;
		a[t] = 1;
	}
	int ans = 1e9 + 7;
	for (int i = 1; i <= n; ++i)
		if (a[i])
			for (ii e : g[i])
				if (!a[e.first])
					ans = min(ans, e.second);
	cout << (ans == 1e9 + 7 ? -1 : ans);
	return 0;
}
